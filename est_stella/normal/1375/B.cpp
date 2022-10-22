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

int a[333][333];
int b[333][333];

void solve() {
	int n, m;
	cin >> n >> m;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> a[i][j];
		}
	}

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			b[i][j] = 4;
			if(i == 1 || i == n) b[i][j]--;
			if(j == 1 || j == m) b[i][j]--;

			if(a[i][j] > b[i][j]) {
				cout << "NO\n";
				return;
			}
		}
	}

	cout << "YES\n";

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cout << b[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	fast;
	int t;

	cin >> t;

	while(t--) {
		solve();
	}
}