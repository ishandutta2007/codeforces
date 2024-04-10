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
void solve() {
	ll a, b;
	cin >> a >> b;
	if (a == 1 || b == 1) {
		cout << 0 << ln;
		return;
	}
	a = min(a, b*b - 1);
	b = min(a - 1, b);
	ll ans;
	ll t = sqrt(a + 1);
	t--;
	while (t <= (a / (t + 2))) t++;
	ans = t * (t - 1) / 2;
	t = max((ll)1, t);
	ll prev = b + 1;
	ll k = a / (b + 1) + 1;
	while (1) {
		ll n = a / k;
		if (n > prev) {
			k++;
			continue;
		}
		if (n <= t + 1) {
			n = t + 1;
			ans += (prev - n)*(k - 1);
			prev = n;
			break;
		}
		else {
			ans += (prev - n)*(k - 1);
			prev = n;
			k++;
		}
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