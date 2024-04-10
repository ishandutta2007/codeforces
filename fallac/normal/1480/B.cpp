#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pp;
#define MAX 101010
#define MOD 993244853
#define INF 2147483647
#define pb push_back
#define all(v) v.begin(), v.end()
#define abs(x) ((x)>0?(x):-(x))
#define sortv(v) sort(all(v))
#define sortvc(v, cmp) sort(all(v), cmp)
#define ln '\n'
#define yes "YES"
#define no "NO"
pair<ll, ll> arr[MAX];
void init() { 
	ios::sync_with_stdio(false);
	cin.tie(0);
}
void solve() {
	ll A, B, N;
	cin >> A >> B >> N;
	ll i, a, b;
	for (i = 1; i <= N; i++) cin >> arr[i].first;
	for (i = 1; i <= N; i++) cin >> arr[i].second;
	sort(arr + 1, arr + N + 1);
	int c = 1;
	for (i = 1; i <= N; i++) {
		if (B < 0) {
			c = 0;
			break;
		}
		ll t = arr[i].second % A ? arr[i].second / A + 1 : arr[i].second / A;
		B -= (t - 1) * arr[i].first;
		if (B > 0) {
			if (i == N) break;
			else B -= arr[i].first;
		}
		else {
			c = 0;
			break;
		}
	}
	if (!c) cout << no << ln;
	else cout << yes << ln;
}
int main() {
	init();
	ll T;
	cin >> T;
	while (T-- > 0) solve();
	return 0;
}