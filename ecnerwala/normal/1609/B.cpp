#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, Q; cin >> N >> Q;
	string S; cin >> S;
	int ans = 0;
	auto val = [&](int a) -> bool {
		return 0 <= a && a+2 < N && S[a] == 'a' && S[a+1] == 'b' && S[a+2] == 'c';
	};
	for (int i = 0; i < N; i++) ans += val(i);

	for (int q = 0; q < Q; q++) {
		int i; char c; cin >> i >> c; i--;
		ans -= val(i-2) + val(i-1) + val(i);
		S[i] = c;
		ans += val(i-2) + val(i-1) + val(i);
		cout << ans << '\n';
	}

	return 0;
}