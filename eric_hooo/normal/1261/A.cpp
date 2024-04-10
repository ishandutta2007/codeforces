#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

char s[2010];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n, k; scanf("%d%d", &n, &k);
		k--;
		scanf("%s", s);
		vector <pii> ans;
		for (int i = 0; i < 2 * k; i++) {
			char p = i & 1 ? ')' : '(';
			int flag = 0;
			for (int j = i; j < n; j++) {
				if (s[j] == p) {
					flag = 1;
					ans.push_back(mp(i, j));
					for (int k = 0; i + k < j - k; k++) {
						swap(s[i + k], s[j - k]);
					}
					break;
				}
			}
			assert(flag);
		}
		int m = n - 2 * k >> 1;
		for (int i = 2 * k; i < 2 * k + m; i++) {
			char p = '(';
			int flag = 0;
			for (int j = i; j < n; j++) {
				if (s[j] == p) {
					flag = 1;
					ans.push_back(mp(i, j));
					for (int k = 0; i + k < j - k; k++) {
						swap(s[i + k], s[j - k]);
					}
					break;
				}
			}
			assert(flag);
		}
		for (int i = 2 * k + m; i < 2 * k + m * 2; i++) {
			char p = ')';
			int flag = 0;
			for (int j = i; j < n; j++) {
				if (s[j] == p) {
					flag = 1;
					ans.push_back(mp(i, j));
					for (int k = 0; i + k < j - k; k++) {
						swap(s[i + k], s[j - k]);
					}
					break;
				}
			}
			assert(flag);
		}
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++) {
			printf("%d %d\n", ans[i].fi + 1, ans[i].se + 1);
		}
	}
	return 0;
}