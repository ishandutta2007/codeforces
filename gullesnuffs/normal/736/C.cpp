#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

vector<int> adj[105];
int n, k;

struct State{
	int node, disUp, disDown;

	bool operator<(const State &other) const{
		if(node != other.node)
			return node < other.node;
		if(disUp != other.disUp)
			return disUp < other.disUp;
		return disDown < other.disDown;
	};
};

map<State, ll> cache;

ll rec(int node, int parent, int disUp, int disDown){
	if(disUp > k && disDown > k)
		return 0;
	State s;
	s.node=node;
	s.disUp=disUp;
	s.disDown=disDown;
	if(cache.count(s))
		return cache[s];
	ll waysSmaller=1, waysLarger=1;
	int newDisUp=min(disUp+1, disDown+1);
	if(newDisUp > k+1)
		newDisUp=k+1;
	bool any=0;
	for(auto to : adj[node]){
		if(to == parent)
			continue;
		any=1;
		ll sum=0;
		/*rep(i,0,disDown-1){
			sum += rec(to, node, newDisUp, i);
		}*/
		rep(i,disDown,2*k+4){
			sum += rec(to, node, newDisUp, i);
		}
		sum %= MOD;
		waysSmaller *= sum;
		waysSmaller %= MOD;
		if(disDown){
			sum += rec(to, node, newDisUp, disDown-1);
		}
		else{
			waysSmaller=0;
			/*rep(i,0,2*k+3){
				sum += rec(to, node, 1, i);
			}*/
		}
		sum %= MOD;
		waysLarger *= sum;
		waysLarger %= MOD;
	}
	if(!any)
		return (disDown == 0 || disDown == k+1);
	ll ret = waysLarger - waysSmaller;
	ret %= MOD;
	if(ret < 0)
		ret += MOD;
	cache[s]=ret;
	return ret;
}

int main(){
	scanf("%d%d", &n, &k);
	rep(i,0,n-1){
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ll ans=0;
	rep(disDown,0,k+1){
		ans += rec(0, -1, k+1, disDown);
		ans %= MOD;
	}
	cout << ans << endl;
}