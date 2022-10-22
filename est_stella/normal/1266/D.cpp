#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(NULL)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define pre(a) cout<<fixed; cout.precision(a)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

int n, m;
ll flow[100010];
vector<int> pos, neg;
vector<pair<pll,ll>> ans;

int main() {
	fast;

	cin >> n >> m;

	for(int i=1; i<=m; i++) {
		ll u, v, d;
		cin >> u >> v >> d;

		flow[u] += d;
		flow[v] -= d;
	}

	for(int i=1; i<=n; i++) {
		if(flow[i] > 0) pos.pb(i);
		if(flow[i] < 0) neg.pb(i);
	}

	int ind = 0;
	for(int i=0; i<pos.size(); ) {
		ll t = min(abs(flow[neg[ind]]), abs(flow[pos[i]]));
		flow[pos[i]] -= t;
		flow[neg[ind]] += t;

		ans.pb({{pos[i], neg[ind]}, t});

		if(flow[pos[i]] == 0 && i < pos.size()) i++;
		if(flow[neg[ind]] == 0 && ind < neg.size()) ind++;
	}

	cout << ans.size() << "\n";

	for(auto i : ans) {
		cout << i.fi.fi << " " << i.fi.se << " " << i.se << "\n";
	}	
}