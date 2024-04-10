#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define pre(a) cout << fixed; cout.precision(a);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

ll n, k;
int a[200010];

void solve() {
	cin >> n >> k;

	int mn = inf;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		if(k & 1) a[i] = -a[i];

		mn = min(mn, a[i]);
	}

	for(int i=1; i<=n; i++) {
		cout << a[i] - mn << " ";
	}
	cout << "\n";
}

int main() {
	fast;

	int t;
	cin >> t;

	while(t--) {
		solve();
	}
}