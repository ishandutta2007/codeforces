#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2.1e5;
int N;
ll A[MAXN];
ll K;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);
	int i = N / 2;
	ll cnt = 1;
	ll ans = A[i];

	while (K > 0 && i + 1 < N) {
		ll v = min(K / cnt, A[i+1] - ans);
		ans += v;
		K -= v * cnt;
		cnt++;
		i++;
	}

	if (K > 0) {
		ans += K / cnt;
	}
	cout << ans << '\n';

	return 0;
}