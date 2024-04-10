#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const ll inf=1e10;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n;
ll dp[N][26];
char s[N];
void Solve(ll *f,ll *g){
	int len=strlen(s+1);
	int w=0;
	for(int i=1;i<=len;++i){
		if(s[i]^s[i-1])w=1;
		else ++w;
		int c=s[i]-'a';
		f[c]=max(f[c],1LL*w);
	}
	if(w==len){
		int c=s[1]-'a';
		f[c]=min(inf,max(f[c],g[c]+(g[c]+1)*len));
		for(int c=0;c<26;++c){
			if(g[c])f[c]=max(f[c],1LL);
		}
	}
	else{
		for(int c=0;c<26;++c){
			if(!g[c])continue;
			int i=0,j=len+1;
			while(i<len&&s[i+1]-'a'==c)++i;
			while(j>1&&s[j-1]-'a'==c)--j;
			f[c]=max(f[c],(ll)i+(len-j+1)+1);
		}	
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		Solve(dp[i],dp[i-1]);
	}
	printf("%lld\n",*max_element(dp[n],dp[n]+26));
	return 0;
}