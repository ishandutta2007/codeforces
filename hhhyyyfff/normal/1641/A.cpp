#include <bits/stdc++.h>

using namespace std;

multiset<int> st;
int t, n, x, ai, ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &x);
		st.clear();
		while (n--) {
			scanf("%d", &ai);
			st.insert(ai);
		}
		ans = 0;
		while (!st.empty()) {
			if (*st.begin() > INT_MAX / x) break;
			auto it = st.find(*st.begin() * x);
			if (it == st.end()) {
				++ans;
				st.erase(st.begin());
			} else {
				st.erase(it);
				st.erase(st.begin());
			}
		}
		printf("%d\n", ans + st.size());
	}
	return 0;
}