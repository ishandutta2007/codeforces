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
ll arr[MAX];
void init() { 
	ios::sync_with_stdio(false);
	cin.tie(0);
}
ll query(int x) {
	if (arr[x]) return arr[x];
	cout << '?' << ' ' << x << ln;
	cout.flush();
	ll ret;
	cin >> ret;
	return ret;
}
void solve() {
	ll N;
	cin >> N;
	arr[0] = INF;
	arr[N + 1] = INF;
	arr[1] = query(1);
	ll l, r;
	l = 0;
	r = N + 1;
	ll p, q, pv;
	while (r - l > 3) {
		p = (l * 2 + r) / 3;
		q = (l + 2 * r) / 3;
		arr[p] = query(p);
		arr[q] = query(q);
		ll m = min(arr[l], arr[r]);
		if ((arr[p] < m) && (arr[q] < m)) {
			if (arr[p] < arr[q]) r = q, pv = p;
			else l = p, pv = q;
		}
		else if ((arr[p] < m) || (arr[q] < m)) {
			if (arr[p] < m) r = q, pv = p;
			else l = p, pv = q;
		}
		else {
			l = p;
			r = q;
		}
	}
	ll i;
	for (i = l; i <= r; i++) {
		arr[i] = query(i);
	}
	ll ans;
	for (i = l + 1; i <= r - 1; i++) {
		if (arr[i] < min(arr[i - 1], arr[i + 1])) {
			ans = i;
			break;
		}
	}
	cout << '!' << ' ' << ans << ln;
	cout.flush();
}
int main() {
	init();
	solve();
	return 0;
}