#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m,k;
vector<int>vec;
vector<P1>edge;
struct uf{
	int par[100005],ran[100005];
	void init(){ for(int i=0;i<100005;i++) par[i] = i, ran[i] = 0; }
	int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
	void unite(int x,int y){
		x = find(x); y = find(y); if(x==y) return;
		if(ran[x] < ran[y]) par[x] = y;
		else{
			par[y] = x;
			if(ran[x] == ran[y]) ran[x]++;
		}
	}
	bool same(int x,int y){ return find(x)==find(y); }
}kaede;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;i++){
		int x; scanf("%d",&x); vec.pb(x);
	}
	for(int i=0;i<m;i++){
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		edge.pb(mp(c,mp(a,b)));
	}
	SORT(edge);
	int lb = -1, ub = m-1;
	while(ub-lb > 1){
		int mid = (lb+ub)/2;
		kaede.init();
		for(int j=0;j<=mid;j++){
			kaede.unite(edge[j].sc.fi,edge[j].sc.sc);
		}
		for(int j=0;j<vec.size();j++){
			if(kaede.find(vec[j]) != kaede.find(vec[0])){
				goto bad;
			}
		}
		ub = mid; continue;
		bad:; lb = mid;
	}
	for(int i=0;i<k;i++) printf("%d\n",edge[ub].fi);
}