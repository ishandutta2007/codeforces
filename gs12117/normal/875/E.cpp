#include<cstdio>
#include<set>
using namespace std;
int n, sa, sb;
int loc[100100];
int para(int x) {
	set<int> s;
	s.insert(sa);
	for (int i = 0; i <= n; i++) {
		while (s.size() > 0 && *s.begin() < loc[i] - x) {
			s.erase(*s.begin());
		}
		while (s.size() > 0 && *s.rbegin() > loc[i] + x) {
			s.erase(*s.rbegin());
		}
		if (s.size() == 0)return 0;
		s.insert(loc[i]);
	}
	return 1;
}
int main() {
	scanf("%d%d%d", &n, &sa, &sb);
	loc[0] = sb;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &loc[i]);
	}
	int ans = -3;
	for (int i = 29; i >= 0; i--) {
		ans += 1 << i;
		if (para(ans) == 1)ans -= 1 << i;
	}
	ans++;
	printf("%d", ans);
	return 0;
}