#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
int n,Q,s[26][N];
char c[N];
int main(){
	n=read(),Q=read();
	scanf("%s",c+1);
	for(int i=1;i<=n;++i){
		for(int j=0;j<26;++j){
			s[j][i]=s[j][i-1];		
		}
		++s[c[i]-'a'][i];
	}
	while(Q--){
		int l=read(),r=read();
		int ans=0;
		for(int j=0;j<26;++j){
			ans+=(j+1)*(s[j][r]-s[j][l-1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}