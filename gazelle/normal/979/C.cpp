#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#include<time.h>
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<(ll)m; i++)
#define FOR(i,n,m) for(long long i=n; i<(ll)m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

ll n,x,y;
vector<vector<ll>> graph;

ll dfs1(ll pos, ll par, bool& d) {
	if(pos==y) {
		d=true;
		return 0;
	}
	ll ret=1;
	REP(i,(ll)graph[pos].size()) {
		if(graph[pos][i]==par) continue;
		bool f=false;
		ll buf=dfs1(graph[pos][i],pos,f);
		if(f) d=true;
		else ret+=buf;
	}
	return ret;
}
ll dfs2(ll pos, ll par, bool& d) {
	if(pos==x) {
		d=true;
		return 0;
	}
	ll ret=1;
	REP(i,(ll)graph[pos].size()) {
		if(graph[pos][i]==par) continue;
		bool f=false;
		ll buf=dfs2(graph[pos][i],pos,f);
		if(f) d=true;
		else ret+=buf;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>x>>y;
	x--; y--;
	graph.resize(n);
	REP(i,n-1) {
		ll a,b;
		cin>>a>>b;
		a--;
		b--;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	ll ans=n*n-n;
	bool hoge1=false,hoge2=false;
	ll nf=dfs1(x,-1,hoge1),nb=dfs2(y,-1,hoge2);
	cout<<ans-nf*nb<<endl;
}