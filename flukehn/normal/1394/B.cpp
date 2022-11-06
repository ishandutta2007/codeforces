#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define se second
#define pb push_back
typedef pair<int,int> pa;
const int N=2e5+11;
vector<pa> e[N];
int n,m,k,ans;
typedef unsigned long long ull;
typedef unsigned int ui;
ull rnd(){
	ull a=rand(),b=rand(),c=rand(),d=rand();
	return (a<<45)^(b<<30)^(c<<15)^d;
}
ull a[N],f[10][10],tot;
void dfs(int x,ull s){
	if(x==k+1){
		ans+=(s==tot);
		return;
	}
	for(int i=0;i<x;++i)
		dfs(x+1,s^f[x][i]);
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	srand(time(0));
	cin>>n>>m>>k;
	int i,j,x,y,z;
	for(i=1;i<=n;++i){
		a[i]=rnd();
		tot^=a[i];
	}
	for(i=1;i<=m;++i){
		cin>>x>>y>>z;
		e[x].pb(mp(z,y));
	}
	for(i=1;i<=n;++i){
		sort(e[i].begin(),e[i].end());
		z=e[i].size();
		for(j=0;j<z;++j){
			f[z][j]^=a[e[i][j].se];
		}
	}
	dfs(2,f[1][0]);
	cout<<ans<<"\n";
#ifdef flukehn
	cerr<<"time = "<<clock()<<endl;
#endif
}