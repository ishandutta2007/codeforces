#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define em emplace
#define mp make_pair
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const long long INF = 1e18;  
const int inf = 1e9;

int n;
vector<int> v[300010];
int up[300010];

void solve() {
	cin >> n;

	up[0] = inf;
	for(int i=1; i<=n; i++) v[i].clear(), up[i] = inf;

	for(int i=1; i<=n; i++) {
		int a;
		cin >> a;

		v[a].eb(i);
	}

	for(int i=1; i<=n; i++) {
		int p = 0, x = 0;
		for(auto j : v[i]) {
			x = max(x, j - p);
			p = j;
		}
		x = max(x, n + 1 - p);

		up[x] = min(up[x], i);
	}

	for(int i=1; i<=n; i++) {
		up[i] = min(up[i], up[i-1]);
	}

	for(int i=1; i<=n; i++) {
		if(up[i] == inf) cout << "-1 ";
		else cout << up[i] << " ";
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