#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		string S; cin >> S;
		int N = int(S.size());
		int st = N+10;
		int en = st;
		vector<int> cnt(2*N+30);
		for (char c : S) {
			if (c == '0') {
				cnt[en++]++;
			} else if (c == '1') {
				cnt[--en]++;
			} else assert(false);
		}
		// we got to get from st to en as well as we can
		string res; res.reserve(N);
		for (int z = 0; z < N; z++) {
			// see if we can go up
			// there must exist an edge, and also we can't disconnect the graph
			if (cnt[st] > 0 && (cnt[st] >= 2 || cnt[st-1] == 0)) {
				cnt[st]--;
				st++;
				res += '0';
			} else {
				assert(cnt[st-1] > 0);
				cnt[st-1]--;
				st--;
				res += '1';
			}
		}
		assert(st == en);
		cout << res << '\n';
	}

	return 0;
}

// if you have (a)(b) such that sum(a) == 0 and sum(b) == 0, you can get to (b)(a) with the reversing trick
// Consider same/diff between chars (flip doesn't affect that)
// You have 0 sum iff # 00 == # 11, including the boundaries

// If the boundaries are different, you should just shrink by 1