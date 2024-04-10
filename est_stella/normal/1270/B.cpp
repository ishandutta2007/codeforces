#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const long long INF = 1e18;  
const int inf = 1e9;

int n;
int a[200010];

void solve() {
	cin >> n;

	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for(int i=1; i<n; i++) {
		if(abs(a[i] - a[i+1]) > 1) {
			cout << "YES\n";
			cout << i << " " << i+1 << "\n";
			return;
		}
	}

	cout << "NO\n";
}

int main() {
	fast;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}