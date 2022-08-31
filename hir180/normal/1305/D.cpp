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
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
int n;
vector<P>query;
vector<int>ans[1005];
vector<int>edge[1005];
 
 
#define SZ 2005
P ar[SZ*2]={};
int pos[SZ]={},id=0,up[SZ],dep[SZ];
P mn[20][SZ*2]={};
int sz[SZ*2]={};
struct LCA{
	//SZ
	//edge[]
	
	void dfs(int v,int u,int d){
		pos[v] = id; up[v] = u; dep[v] = d;
		ar[id++] = mp(d,v);
		for(int i=0;i<edge[v].size();i++){
			if(edge[v][i] == u) continue;
			dfs(edge[v][i],v,d+1);
			ar[id++] = mp(d,v);
		}
	}
	void prepare(int x){
	    id = 0;
		dfs(x,-1,0);
		for(int i=0;i<id;i++) mn[0][i] = ar[i];
		for(int j=0;j<19;j++){
			for(int i=0;i<id;i++){
				if(i+(1<<j) >= id) mn[j+1][i] = mn[j][i];
				else mn[j+1][i] = min(mn[j][i], mn[j][i+(1<<j)]);
			}
		}
		for(int i=1;i<SZ*2;i++){
			for(int j=0;j<20;j++){
				if((1<<j) <= i && i <= (2<<j)){
					sz[i] = j;
					break;
				}
			}
		}
	}
	int get(int a,int b){
		int len = max(pos[a],pos[b]) - min(pos[a],pos[b]) + 1;
		int ty = sz[len];
		P p = min(mn[ty][min(pos[a],pos[b])], mn[ty][max(pos[a],pos[b])-(1<<ty)+1]);
		return p.second;
	}
}kaede;
//plz don't put such a shitty reactive in the middle of contests XD
typedef vector<int> vi;

vi dfs(int v,int u){
	vector<vi>vv;
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		auto att = dfs(edge[v][i],v);
		vv.pb(att);
	}
	if(vv.empty()){
		return vector<int>(1,v);
	}
	while(1){
		vector<int>id;
		int sz = 0;
		rep(i,vv.size()){
			if(vv[i].size()) {
				id.pb(i);
				sz += vv[i].size();
			}
		}
		if(sz <= 2) break;
		if(id.size() <= 1) break;
		query.pb(P(vv[id[0]].back(), vv[id[1]].back()));
		vv[id[0]].pop_back();
		vv[id[1]].pop_back();
	}
	vector<int>ret;
	rep(i,vv.size()) if(vv[i].size()) for(auto aa:vv[i]) ret.pb(aa);
	return ret;
}
int main(){
	scanf("%d",&n);
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	auto v = dfs(1,-1);
	if(v.size()%2 == 1 || query.size()+(v.size())/2 < n/2){
		if(v.size()){
		    query.pb(mp(1,v.back()));
		    if(v.size()%2 == 1) v.pop_back();
		}
	}
	rep(i,v.size()/2){
		query.pb(mp(v[i*2], v[i*2+1]));
	}
	repn(i,n){
		kaede.prepare(i);
		rep(j,query.size()){
			int a = query[j].fi;
			int b = query[j].sc;
			ans[i].pb(kaede.get(a,b));
		}
	}
	vector<int>vii;
	rep(i,query.size()){
		cout<<"? "<<query[i].fi<<" "<<query[i].sc<<endl;
		int ans; cin >> ans;
		vii.pb(ans);
	}
	vector<int>ret;
	repn(i,n) if(ans[i] == vii) ret.pb(i);
	assert(ret.size() == 1);
	cout << "! " << ret[0] << endl;
}