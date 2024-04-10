#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0)
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define pre(a) cout<<fixed; cout.precision(a);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll INF = 1e18;
const int inf = 1e9;

int n, k;
vector<int> g[100010];
bool chk[100010];

int dfs(int x) {
	int ret = 1;
	chk[x] = true;

	for(auto i : g[x]) {
		if(chk[i]) continue;

		ret += dfs(i);
	}

	return ret;
}

int main() {
	fast;

	cin >> n >> k;

	for(int i=0; i<k; i++) {
		int x, y;
		cin >> x >> y;

		g[x].pb(y);
		g[y].pb(x);
	}

	for(int i=1; i<=n; i++) {
		if(chk[i]) continue;
		k -= dfs(i)-1;
	}

	cout << k;
}