#include<bits/stdc++.h>
using namespace std;
#define N 1010
typedef long long ll;
int n,m,a[N],b[N],an,bn;
int match[N];
bool vis[N];
bool dfs(int u){
	for(int v=1;v<=bn;++v){
		if(vis[v])continue;
		if(2*a[u]+b[v]>m||a[u]%b[v])continue;
		vis[v]=1;
		if(!match[v]||dfs(match[v])){
			match[v]=u;
			return true;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1,x;i<=n;++i){
		cin>>x;
		if(x>m/2){
			cout<<-1<<'\n';
			return 0;
		}
		if(x>m/3){
			a[++an]=x;
		}
		else{
			b[++bn]=x;
		}
	}
	for(int i=1;i<=an;++i){
		memset(vis,0,sizeof(vis));
		if(!dfs(i)){
			cout<<-1<<'\n';
			return 0;
		}
	}
	cout<<bn<<'\n';
	for(int i=1;i<=bn;++i){
		if(!match[i]){
			cout<<2*b[i]<<' '<<3*b[i]<<'\n';
		}
		else{
			cout<<b[i]+a[match[i]]<<' '<<b[i]+2*a[match[i]]<<'\n';
		}
	}
	return 0;
}