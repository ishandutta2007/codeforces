#include <bits/stdc++.h>
using namespace std;
#define MAX 500010
#define all(v) v.begin(), v.end()
#define ln '\n'
#define MOD 10007
#define INF 2100000000
#define abs(x) (((x)>0)?(x):(-(x)))
typedef long long ll;
ll a[MAX], b[MAX], c[MAX];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll C;
	cin >> C;
	while (C-- > 0) {
		ll N;
		cin >> N;
		ll i;
		for (i = 1; i <= N; i++) cin >> c[i];
		for (i = 1; i <= N; i++) cin >> a[i];
		for (i = 1; i <= N; i++) cin >> b[i];
		ll sum = abs(a[2] - b[2]);
		ll m = 0;
		for (i = 2; i < N; i++) {
			if (a[i] == b[i]) {
				if (c[i] != 1) m = max(m, sum);
				sum = 0;
			}
			if (c[i] != 1 || c[i - 1] != 1)m = max(sum + c[i] + 1, m);
			sum += 2;
			sum += min(a[i + 1], b[i + 1]) - 1;
			sum += abs(max(a[i + 1], b[i + 1]) - c[i]);
			sum = max(sum, abs(a[i + 1] - b[i + 1]));
		}
		if (a[N] == b[N]) {
			if (c[i] != 1 || c[i - 1] != 1)m = max(m, sum);
			sum = 0;
		}
		sum += c[N] + 1;
		if (c[N] != 1) m = max(m, sum);
		cout << m << ln;
	}
	return 0;
}