#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 100005;
int a[MAXN];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n * 2; i++) scanf("%d", a + i);
		sort(a + 1, a + 1 + n * 2, greater<int>());
		bool yep = 0;
		for (int i = 2; i <= n * 2; i++) {
			multiset<int> s;
			vector<pair<int, int> > ans;
			ans.push_back(make_pair(a[i], a[1]));
			for (int j = 2; j <= n * 2; j++)
				if (i != j) s.insert(a[j]);
			int lst = a[1], flag = 1;
			for (int i = 2; i <= n; i++) {
				int t = *s.rbegin();
				s.erase(s.find(t));
				auto it = s.find(lst - t);
				if (it == s.end()) {
					flag = 0;
					break;
				}
				ans.push_back(make_pair(*it, t));
				lst = t;
				s.erase(it);
			}
			if (flag) {
				puts("YES");
				printf("%d\n", ans[0].first + ans[0].second);
				for (auto &p : ans)
					printf("%d %d\n", p.first, p.second);
				yep = 1;
				break;
			}
		}
		if (!yep) puts("NO");
	}
	return 0;
}