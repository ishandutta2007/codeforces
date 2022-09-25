#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const int B=75;
int n,Q,p[N],g[N],rp[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;++i){
		cin>>p[i];
		rp[p[i]]=i;
	}
	for(int i=1;i<=n;++i){
		g[i]=i;
		for(int j=1;j<=B;++j)g[i]=p[g[i]];
	}
	while(Q--){
		int opt,x,y;
		cin>>opt>>x>>y;
		if(opt==2){
			while(y>=B)x=g[x],y-=B;
			while(y--)x=p[x];
			cout<<x<<'\n';
		}
		else{
			static int nd[N],tot;
			static bool vis[N];
			tot=0;
			for(int u=x,i=1;i<=B;++i,u=rp[u]){
				if(!vis[u])nd[++tot]=u,vis[u]=1;
			}
			for(int u=y,i=1;i<=B;++i,u=rp[u]){
				if(!vis[u])nd[++tot]=u,vis[u]=1;
			}
			swap(rp[p[x]],rp[p[y]]);
			swap(p[x],p[y]);
			for(int j=1;j<=tot;++j){
				int u=nd[j];
				g[u]=u;
				for(int i=1;i<=B;++i)g[u]=p[g[u]];
				vis[u]=0;
			}
		}
	}
	return 0;
}