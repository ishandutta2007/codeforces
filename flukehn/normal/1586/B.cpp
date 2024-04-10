#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
int f[N];
int n,m;
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(cin>>n>>m){
		for(int i=1;i<=n;++i)f[i]=0;
		for(int i=1;i<=m;++i){
			int x,y,z;
			cin>>x>>y>>z;
			f[y]=1;
		}
		int u;
		for(u=1;u<=n;++u)if(!f[u])break;
		for(int i=1;i<=n;++i)if(i!=u){
			cout<<i<<" "<<u<<"\n";
		}
	}
}