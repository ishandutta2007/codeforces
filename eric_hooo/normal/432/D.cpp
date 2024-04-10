#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

char s[100010];
int z[100010];
int cnt[100010];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	int L = 0, R = 0;
	for (int i = 1; i < n; i++){
		if (R < i){
			L = R = i;
			while (R < n && s[R] == s[R - L]) R++;
			z[i] = R - L, R--;
			continue;
		}
		int p = i - L;
		if (z[p] + i - 1 < R){
			z[i] = z[p];
			continue;
		}
		L = i, R++;
		while (R < n && s[R] == s[R - L]) R++;
		z[i] = R - L, R--;
	}
	cnt[n] = 1;
	for (int i = 1; i < n; i++) {
		cnt[z[i]]++;
	}
	for (int i = n; i >= 0; i--) {
		cnt[i] += cnt[i + 1];
	}
	vector <pii> ans;
	ans.push_back(mp(n, 1));
	for (int i = 1; i < n; i++) {
		if (i + z[i] == n) ans.push_back(mp(z[i], cnt[z[i]]));
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d\n", ans[i].fi, ans[i].se);
	}
	return 0;
}