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
ll arr[MAX];
ll c[MAX][2];
ll sum[MAX][2];
void solve() {
	ll N, Q, K;
	cin >> N >> Q >> K;
	ll i, j;
	for (i = 1; i <= N; i++) cin >> arr[i];
	if (arr[1] > 1) c[1][0] = arr[1] - 1;
	if (arr[N] < K) c[N][1] = K - arr[N];
	for (i = 2; i <= N; i++) if (arr[i] > arr[i - 1] + 1 && arr[i] > 1) c[i][0] = arr[i] - arr[i - 1] - 1;
	for (i = 1; i <= N - 1; i++) if (arr[i] + 1 < arr[i + 1] && arr[i] < K) c[i][1] = arr[i + 1] - arr[i] - 1;
	for (i = 1; i <= N; i++) {
		sum[i][0] = c[i][0] + sum[i - 1][0];
		sum[i][1] = c[i][1] + sum[i - 1][1];
	}
	ll l, r;
	for (i = 1; i <= Q; i++) {
		cin >> l >> r;
		if (l == r) {
			ll cnt = 0;
			if (arr[l] < K) cnt += K - arr[l];
			if (arr[l] > 1) cnt += arr[l] - 1;
			cout << cnt << ln;
			continue;
		}
		ll cnt = sum[r - 1][0] + sum[r - 1][1] - sum[l][0] - sum[l][1];
		cnt += c[l][1];
		cnt += c[r][0];
		if (arr[r] < K) cnt += K - arr[r];
		if (arr[l] > 1) cnt += arr[l] - 1;
		cout << cnt << ln;
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}