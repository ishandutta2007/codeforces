#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
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
int T,n,cnt[26];
char s[N];
bool check(int len,string &t){
	bitset<26> vis;
	static char g[N*26];
	int h=0;
	for(auto x:t){
		int c=x-'a';
		for(int i=1;i<=len;++i){
			if(vis[s[i]-'a'])continue;
			g[++h]=s[i];	
		}
		vis[c]=1;			
	}
	if(h^n)return false;
	for(int i=1;i<=n;++i){
		if(g[i]^s[i])return false;
	}
	return true;
}
void Solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;++i){
		++cnt[s[i]-'a'];
	}
	int k=0;
	for(int i=0;i<26;++i){
		k+=cnt[i]>0;	
	}
	int p=n,len=0;
	string ans="";
	do{
		if(p<=0){
			puts("-1");
			return;
		}
		int j=p;
		while(j&&!cnt[s[j]-'a'])--j;
		if(!j){
			puts("-1");
			return;
		}
		int c=s[j]-'a';
		ans+=s[j];
		if(!cnt[c]||cnt[c]%k){
			puts("-1");
			return;
		}
		len+=cnt[c]/k;
		cnt[c]=0;
		p-=len;
		if(p>=j){
			puts("-1");return;
		}
	}while(--k);
	if(p){
		puts("-1");
		return;
	}
	reverse(ans.begin(),ans.end());
	if(!check(len,ans)){
		puts("-1");return;
	}
	for(int i=1;i<=len;++i){
		putchar(s[i]);	
	}
	putchar(' ');
	for(auto c:ans)putchar(c);
	putchar('\n');
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}