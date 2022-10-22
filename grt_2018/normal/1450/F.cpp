#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 100 * 1000 + 10;
int t, n;
int a[nax];
int cnt[nax];

int main() {_
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			cnt[i] = 0;
		}
		int ans = 0;
		cnt[a[1]]++;
		cnt[a[n]]++;
		for(int i = 2; i <= n; ++i) {
			if(a[i] == a[i - 1]) {
				ans++;
				cnt[a[i]]+=2;
			}
		}
		pi mx = {-1, 0};
		for(int i = 1; i <= n; ++i) {
			mx = max(mx, {cnt[i], i});
			//~ cout << cnt[i] << " ";
		}
		//~ cout << "\n";
		if(2 * (mx.ST - 2) <= ((ans + 1) * 2 - 2)) {
			cout << ans << "\n";
			continue;
		}
		int ile = 0;
		for(int i = 2; i <= n; ++i) {
			if(a[i] != a[i - 1]) {
				if(a[i] != mx.ND && a[i - 1] != mx.ND) {
					ile++;
				}
			}
		}
		bool ok = 0;
		for(int i = 0; i < ile; ++i) {
			ans++;
			if(2 * (mx.ST - 2) <= ((ans + 1) * 2 - 2)) {
				ok = 1;
				break;
			}
		}
		if(ok) cout << ans << "\n";
		else cout << "-1\n";
			
	}
	
}