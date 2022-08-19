#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll N, M; cin >> N >> M;
	ll G = __gcd(N, M);
	N /= G, M /= G;

	int Q; cin >> Q;
	while (Q--) {
		int sx; ll sy; int ex; ll ey; cin >> sx >> sy >> ex >> ey;
		sx--, sy--, ex--, ey--;
		sy /= (sx ? M : N);
		ey /= (ex ? M : N);
		cout << ((sy == ey) ? "YES" : "NO") << '\n';
	}

	return 0;
}