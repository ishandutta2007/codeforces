#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
const int B=500000;
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
int n,a[N];
char s[N];
vector<int> G[N<<1],ans;
void dfs(int u){
	while(!G[u].empty()){
		int v=G[u].back();
		G[u].pop_back();
		dfs(v);	
	}
	ans.push_back(u);
}
void Solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		a[i]=a[i-1]+(s[i]=='1'?1:-1);
	}	
	for(int i=B-n;i<=B+n;++i)G[i].clear();
	for(int i=0;i<n;++i){
		G[a[i]+B].push_back(a[i+1]+B);	
	}
	for(int i=B-n;i<=B+n;++i){
		sort(G[i].begin(),G[i].end(),greater<int>());	
	}
	ans.clear();
	dfs(B);
	reverse(ans.begin(),ans.end());
	for(int i=1;i<=n;++i){
		putchar(ans[i]==ans[i-1]+1?'1':'0');	
	}
	putchar('\n');
}
int main(){
	int T=read();
	while(T--){
		Solve();
	}
	return 0;
}