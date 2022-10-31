#include <bits/stdc++.h>
using namespace std;
#define MAX 500010
#define all(v) v.begin(), v.end()
#define ln '\n'
#define MOD 10007
#define INF 2100000000
#define abs(x) ((x)>0?(x):-(x))
typedef long long ll;
ll arr[MAX];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T;
	cin >> T;
	while (T-- > 0) {
		ll N;
		cin >> N;
		ll i;
		ll a;
		map<ll, ll> m;
		bool c = true;
		ll p = 0;
		for (i = 1; i <= 2 * N; i++) {
			cin >> a;
			arr[i] = a;
			m[a]++;
			if (m[a] != 1) p++;
			else p--;
			if (a % 2) c = false;
		}
		ll aaa;
		ll sum = 0;
		sort(arr + 1, arr + 2 * N + 1);
		for (i = 1; i <= N - 1; i++) {
			aaa = arr[(i + 1) * 2] - arr[i * 2];
			if ((aaa < 0) || (aaa % (2 * i))) c = false;
			sum += (N - i)*(aaa / (2 * i));
		}
		ll ab = arr[1] / 2 - sum;
		if (ab%N) c = false;
		ab /= N;
		if (ab <= 0) c = false;
		if (p == 0 && c) cout << "YES" << ln;
		else cout << "NO" << ln;
	}
	return 0;
}