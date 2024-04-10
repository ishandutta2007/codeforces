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

vector<set<ll>> adj;
vector<ll> ans_head;
vector<ll> ans_bottom;
ll dfs(ll pos, ll par) {
	ll sum=0;
	if(pos!=0) sum++;
	for(auto x: adj[pos]) {
		if(x==par) continue;
		sum+=dfs(x,pos);
	}
	if(sum%2) {
		ans_bottom.pb(pos);
		return 1;
	} else {
		ans_head.pb(pos);
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	adj.resize(n);
	REP(i,n) {
		ll p;
		cin>>p;
		if(p==0) continue;
		p--;
		adj[i].insert(p);
		adj[p].insert(i);
	}
	dfs(0,-1);
	vector<ll> seq;
	for(ll i=0; i<(ll)ans_head.size(); i++) seq.pb(ans_head[i]);
	for(ll i=(ll)ans_bottom.size()-1; i>=0; i--) seq.pb(ans_bottom[i]);
	REP(i,n) {
		if((ll)adj[seq[i]].size()%2) {
			cout<<"NO"<<endl;
			return 0;
		}
		for(auto x: adj[seq[i]]) adj[x].erase(seq[i]);
	}
	cout<<"YES"<<endl;
	REP(i,n) cout<<seq[i]+1<<endl;
}