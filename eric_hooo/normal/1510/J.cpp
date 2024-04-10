#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

char s[100010];
vector <pii> all;
vector <int> a;

bool CheckA(int x, int Free) {
	if (!x) return 1;
	if (!Free) return 0;
	if (Free == 1 && (x & 1)) return 0;
	return 1;
}

void AddA(int x, int Free) {
	if (x & 1) a.push_back(2), x -= 3;
	while (x) a.push_back(1), x -= 2;
}

int main() {
	scanf("%s", s + 1); int n = strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i] == '_') continue;
		int j = i; while (j <= n && s[j] == '#') j++;
		all.push_back(mp(i, j - 1)), i = j - 1;
	}
	if (!all.size()) {
		printf("0\n");
		return 0;
	}
	int N = all.size();
	for (int Free = 0; Free <= n / N; Free++) {
		int cur = -1;
		for (int i = 0; i < N; i++) {
			int l = all[i].fi, r = all[i].se, len = r - l + 1 + Free;
			cur += len + 1;
			if (cur > r || cur == r - 1 || !CheckA(r - cur, Free)) goto NXT;
			cur = r;
		}
		if (cur + Free > n || cur + Free == n - 1 || !CheckA(n - cur - Free, Free)) goto NXT;
		cur = -1;
		for (int i = 0; i < N; i++) {
			int l = all[i].fi, r = all[i].se, len = r - l + 1 + Free;
			cur += len + 1, AddA(r - cur, Free), a.push_back(len), cur = r;
		}
		AddA(n - cur - Free, Free);
		printf("%d\n", (int)a.size());
		for (int i = 0; i < a.size(); i++) printf("%d ", a[i]); printf("\n");
		return 0;
		NXT:;
	}
	printf("-1\n");
	return 0;
}