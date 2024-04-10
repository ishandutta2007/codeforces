#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#include<time.h>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,m;
	cin>>n>>m;
	vector<vector<P>> g(n);
	REP(i,m) {
		ll v,u,w;
		cin>>v>>u>>w;
		v--;
		u--;
		g[v].pb(P(u,w));
		g[u].pb(P(v,w));
	}
	vector<ll> a(n);
	REP(i,n) cin>>a[i];
	vector<ll> d(n,INF*INF);
	ll buf=INF*INF,pos=-1;
	REP(i,n) if(a[i]<buf) {
		buf=a[i];
		pos=i;
	}
	priority_queue<P,vector<P>,greater<P>> q;
	REP(i,n) d[i]=a[i];
	REP(i,n) q.push(P(a[i],i));
	while(!q.empty()) {
		ll cost=q.top().first;
		ll p=q.top().second;
		q.pop();
		if(d[p]!=cost) continue;
		REP(i,(ll)g[p].size()) {
			ll edg=g[p][i].second;
			ll adj=g[p][i].first;
			if(d[p]+2*edg<d[adj]) {
				d[adj]=d[p]+2*edg;
				q.push(P(d[adj],adj));
			}
		}
	}
	DUMP(d);
}