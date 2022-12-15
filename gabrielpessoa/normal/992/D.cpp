#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

const int ms = 2e5+5;
const ll mod = 1e9+7;
const int m = 2; // size of matrix

ull a[ms];
int nxt[ms];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	ull k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	nxt[n-1] = n;
	for(int i = n - 2; i >= 0; i--) {
		nxt[i] = a[i+1] == 1 ? nxt[i+1] : i + 1;
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ull p = a[i];
		ull sum = a[i];
		if(p % sum == 0 && p / sum == k) ans++;
		for(int j = i+1; j < n; j = nxt[j]){
			//cout << i << ' ' << j << ' ' << p << ' ' << sum << endl;
			if(p > 5e18/a[j]) {
				break;
			}
			p *= a[j];
			sum += a[j];
			//cout << i << ' ' << j << ' ' << p << ' ' << sum << endl;
			if(p % sum == 0 && p / sum == k) ans++;
			else if(nxt[j] != j + 1) {
				if(p % k == 0) {
					ll divisao = p / k;
					if(p / k > sum && p / k <= sum + nxt[j] - j - 1) {
						ans++;
					}
				}
			}
			sum += nxt[j] - j - 1;
		}
	}
	cout << ans << endl;
	return 0;
}