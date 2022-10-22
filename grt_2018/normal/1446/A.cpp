#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

int t, n;
ll w;
const int nax = 200 * 1000 + 10;
int a[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n >> w;
		ll sum = 0;
		int ok = -1;
		vi ans = {};
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
			if(a[i] > w) continue;
			if(a[i] >= (w + 1) / 2) ok = i + 1;
			else {
				ans.PB(i);
				sum += a[i];
			}
		}
		if(ok != -1) {
			cout << 1 << "\n" << ok << "\n";
			continue;
		}
		if(sum < (w + 1)/2) {
			cout << "-1\n";
			continue;
		}
		ll cur = 0;
		int x = 0;
		while(cur < (w + 1)/2) {
			cur += a[ans[x++]];
		}
		cout << x << "\n";
		for(int i = 0; i < x; ++i) {
			cout << ans[i]+1 << " ";
		}
		cout << "\n";
	}
	
}