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

int n;
int a[200010];

void solve() {
	cin >> n;

	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}

	bool flag = true;

	for(int i=1; i<n; i++) {
		if(a[i] != a[i+1]) flag = false;
	}

	if(flag) cout << n << "\n";
	else cout << 1 << "\n";
}

int main() {
	fast;
	
	int t;

	cin >> t;

	while(t--) {
		solve();
	}
}