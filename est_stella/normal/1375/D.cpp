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

int n;
int a[1010];
int cnt[1010] = {};

int f() {
	for(int i=0; i<=n; i++) {
		if(cnt[i] == 0) return i;
	}
}

void solve() {
	cin >> n;
	vector<int> ans;

	for(int i=0; i<=n; i++) cnt[i] = 0;

	for(int i=1; i<=n; i++) {
		cin >> a[i];

		cnt[a[i]]++;
	}

	for(int i=1; i<=n; i++) {
		int k = f();

		while(k < i) {
			cnt[k]++;
			cnt[a[k+1]]--;
			a[k+1] = k;

			//cout << i << "!!! " << k << "\n";
			ans.eb(k+1);

			k = f();
		}

		if(a[i] != i-1) {
			cnt[a[i]]--;
			cnt[k]++;
			a[i] = k;

			//cout << i << "??? " << k << "\n";

			ans.eb(i);
		}
	}

	int k = f();

	while(k < n) {
		cnt[k]++;
		cnt[a[k+1]]--;
		a[k+1] = k;

		ans.eb(k+1);

		//cout << n+1 << "!!! " << k << "\n";

		k = f();
	}

	cout << ans.size() << "\n";

	for(auto i : ans) {
		cout << i << " ";
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