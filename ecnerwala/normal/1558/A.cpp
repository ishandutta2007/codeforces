#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int A, B; cin >> A >> B;
		int S = A+B;
		std::vector<bool> is_good(S+1);
		for (int na = S/2; na <= S-S/2; na++) {
			for (int abreak = 0; abreak <= min(na, A); abreak++) {
				int bhold = na - abreak;
				int bbreak = B - bhold;
				if (bbreak < 0) continue;
				is_good[abreak + bbreak] = true;
			}
		}

		std::vector<int> ans; ans.reserve(S+1);
		for (int i = 0; i <= S; i++) if (is_good[i]) ans.push_back(i);
		cout << ans.size() << '\n';
		for (int z = 0; z < int(ans.size()); z++) {
			cout << ans[z] << " \n"[z+1==int(ans.size())];
		}
	}

	return 0;
}