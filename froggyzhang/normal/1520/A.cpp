#include<bits/stdc++.h>
using namespace std;
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
int T,n,vis[26];
char s[55];
inline bool Solve(){
	n=read();
	memset(vis,0,sizeof(vis));
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		int c=s[i]-'A';
		if(vis[c]&&s[i]!=s[i-1])return false;
		vis[c]=1;
	}
	return true;
}
int main(){
	T=read();
	while(T--){
		printf(Solve()?"YES\n":"NO\n");
	}
	return 0;
}