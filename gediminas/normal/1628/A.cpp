#include <bits/stdc++.h>
using namespace std;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
6
5
1 0 2 0 3
8
2 2 3 4 0 1 2 0
4
1 2 3 4
5
0 1 2 3 4
4
0 1 1 0
10
0 0 2 1 1 1 0 0 1 1

*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int TESTS;
	cin >> TESTS;

	for (int TESTT = 0; TESTT < TESTS; ++TESTT) {
		int n;
		cin >> n;
		vector<int> a(n);
		map<int, int> cnt;

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			cnt[a[i]]++;
		}

		int mex = 0;

		while (cnt[mex]) {
			mex++;
		}

		int mext = mex;

		map<int, int> cntr;
		int mexr = 0;
		vector<int> ans;

		for (int i = 0; i < n; ++i) {
			cntr[a[i]]++;
			cnt[a[i]]--;

			if (cnt[a[i]] == 0) {
				mex = min(mex, a[i]);
			}

			while (cntr[mexr]) {
				mexr++;
			}

			if (mexr == mext) {
				ans.push_back(mexr);
				mext = mex;
				mexr = 0;
				cntr.clear();
			}
		}

		cout << ans.size() << "\n";

		for (auto &&i : ans) {
			cout << i << " ";
		}

		cout << "\n";

	}
}