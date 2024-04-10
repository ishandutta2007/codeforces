#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vint;
typedef queue<ll> qint;
typedef set<ll> sint;
typedef pair<ll, ll> pp;
typedef vector<ll>::iterator vit;
typedef set<ll>::iterator sit;
typedef map<ll, ll>::iterator mit;
#define MAX 401010
#define MOD 993244853
#define INF 2147483647
#define lll ll, ll
#define pb push_back
#define all(v) v.begin(), v.end()
#define abs(x) ((x)>0?(x):-(x))
#define sortv(v) sort(all(v))
#define sortvc(v, cmp) sort(all(v), cmp)
#define range(it, ds) it=(ds).begin();it!=(ds).end;it++
#define ln '\n'
#define yes "YES"
#define no "NO"
pair<int, pair<int, int>> arr[MAX];
ll f(ll a, ll b) {
	ll ret = 0;
	while (a > 0)ret++, a /= b;
	return ret;
}
void solve() {
	ll a, b;
	cin >> a >> b;
	ll ans = 30;
	if (b > 1) ans = f(a, b);
	ll i;
	for (i = 1; i <= 30; i++) {
		ans = min(ans, f(a, b + i) + i);
	}
	cout << ans << ln;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T;
	cin >> T;
	while (T-- > 0)solve();
	return 0;
}