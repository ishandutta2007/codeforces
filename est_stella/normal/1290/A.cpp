#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
#define mp make_pair
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const long long INF = 1e18;  
const int inf = 1e9;

int n, m, k;
int a[100010];

void solve() {
	cin >> n >> m >> k;

	k = min(k, m-1);

	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}

	vector<int> v;
	for(int i=1; i<=m; i++) {
		v.eb(max(a[i], a[i+n-m]));
	}

	int ans = -inf;
	for(int i=0; i<=k; i++) {
		int mn = inf;
		for(int j=i; j < m-k+i; j++) {
			mn = min(mn, v[j]);
		}
		
		ans = max(ans, mn);
	}

	cout << ans << "\n";
}

int main() {
	fast;

	int t;
	cin >> t;

	while(t--) {
		solve();
	}
}