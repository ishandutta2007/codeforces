#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,k,a[200005][6],v[200005];
vector<vector<int>>pm;
int go[125][125];
int las[125];
int par[125];
vector<int>L[125];
void init(){ for(int i=0;i<125;i++) {
	par[i] = i; 
}}
int find(int x){ if(x == par[x]) return par[x]; else return par[x] = find(par[x]);}
int unite(int x,int y){
	x = find(x); y = find(y); if(x==y) return 0;
	par[x] = y;
	return 1;
}
bool same(int x,int y){ return find(x)==find(y); }
int check[125];
int main(){
	scanf("%d%d",&n,&k); 
	vector<int>vec; rep(i,k) vec.pb(i);
	do{
		pm.pb(vec);
	}while(next_permutation(vec.begin(),vec.end()));
	SORT(pm);
	srand((unsigned)time(NULL));
	rep(i,n){
		vector<int>vi;
		rep(j,k){ scanf("%d",&a[i][j]); a[i][j]--; vi.pb(a[i][j]); }
		int x = POSL(pm,vi); assert(pm[x] ==  vi);
		v[i] = x;
	}
	rep(i,pm.size()) rep(j,pm.size()){
		vector<int>vi = pm[i],nw;
		rep(k,pm[j].size()) nw.pb(vi[pm[j][k]]);
		go[i][j] = POSL(pm,nw);
	}
	rep(i,pm.size()) assert(go[0][i] == i);
	rep(i,k) assert(pm[0][i] == i);
	rep(i,pm.size()){
		las[i] = INF;
		check[i] = i;
	}
	ll ans = 0;
	for(int i=n-1;i>=0;i--){
		las[v[i]] = i;
		rep(j,pm.size()){
			if(check[j] == v[i]){
				for(int k=j;k>=1;k--) {
				        int a = check[k];
				        check[k] = check[k-1];
				        check[k-1] = a;
				        //swap(check[k],check[k-1]);
				}
				break;
			}
		}
		//rep(j,pm.size()-1) assert(las[check[j]] <= las[check[j+1]]);
		init();
		int sz = pm.size();
		int pre = i-1; int x = 0;
		rep(j,pm.size()){
			int i = check[j];
			if(las[i] == INF) break;
			if(find(i) == find(0)) continue;
			//(pre,las[i]) -> pm.size() /sz
			ans += 1LL * (las[i]-pre-1) * ((int)(pm.size()/sz));
			rep(jj,pm.size()){
				sz -= unite(jj,go[jj][i]);
			}
			assert(pm.size()%sz == 0);
			pre = las[i]-1;
		}
		//(pre,n) -> pm.size() /sz
		ans += 1LL * (n-pre-1) * ((int)(pm.size()/sz));
	}
	cout << ans << endl;
}