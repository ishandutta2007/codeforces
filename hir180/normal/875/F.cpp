#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int par[200005],ran[200005];
bool used[200005],cyc[200005];
void init(){ for(int i=0;i<200005;i++) par[i] = i; }
int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
bool unite(int x,int y){
	x = find(x); y = find(y); if(x==y) return 0;
	if(cyc[x] && cyc[y]) return 0;
	if(ran[x] < ran[y]){
		par[x] = y;
		if(cyc[x]||cyc[y]) cyc[x] = cyc[y] = 1;
	}else{
		par[y] = x;
		if(ran[x] == ran[y]) ran[x]++;
		if(cyc[x]||cyc[y]) cyc[x] = cyc[y] = 1;
	}
	return 1;
}
bool same(int x,int y){ return find(x)==find(y); }
int n,m; ll ans;
vector<P1>edge;
int main(){
	cin>>n>>m; init();
	rep(i,m){
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		edge.pb(mp(c,mp(a,b)));
	}
	SORT(edge);
	reverse(edge.begin(),edge.end());
	for(int i=0;i<m;i++){
		if(!same(edge[i].sc.fi,edge[i].sc.sc)){
			if(unite(edge[i].sc.fi,edge[i].sc.sc)){
				used[i] = 1;
				ans += edge[i].fi;
			}
		}
		else{
			int x = find(edge[i].sc.fi);
			if(!cyc[x]){
				cyc[x] = 1;
				ans += edge[i].fi;
			}
		}
	}
	printf("%lld\n",ans);
}