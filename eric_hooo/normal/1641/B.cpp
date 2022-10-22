#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

vector <int> a;
vector <pii> op;
vector <int> ans;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		goto BEG;
		BAD:;
		printf("-1\n");
		continue;
		BEG:;
		int n; scanf("%d", &n);
		a.clear();
		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			a.push_back(x);
		}
		ans.clear(), op.clear();
		while (a.size()) {
			int x = a.back(); a.pop_back();
			vector <int> seq;
			while (a.size() && a.back() != x) seq.push_back(a.back()), a.pop_back();
			if (!a.size()) goto BAD;
			a.pop_back();
			ans.push_back((seq.size() + 1) * 2);
			for (auto it : seq) {
				op.push_back(mp(a.size(), it));
				a.push_back(it);
			}
		}
		printf("%d\n", (int)op.size());
		for (auto it : op) {
			printf("%d %d\n", it.fi, it.se);
		}
		reverse(ans.begin(), ans.end());
		printf("%d\n", (int)ans.size());
		for (auto it : ans) {
			printf("%d ", it);
		}
		printf("\n");
	}
	return 0;
}