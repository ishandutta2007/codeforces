#include <cstdio>
#include <cstring>

#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

typedef long long ll;

const int N = 100010;

int n, m;
char s[N], t[N];
int sNotA[N], tNotA[N], sLeadA[N], tLeadA[N];

int main() {
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1);
	m = strlen(t + 1);
	for (int i = 1; i <= n; ++i) {
		sNotA[i] = sNotA[i - 1] + (s[i] != 'A');
		if (s[i] == 'A')
			sLeadA[i] = sLeadA[i - 1] + 1;
	}
	for (int i = 1; i <= m; ++i) {
		tNotA[i] = tNotA[i - 1] + (t[i] != 'A');
		if (t[i] == 'A')
			tLeadA[i] = tLeadA[i - 1] + 1;
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		int s1, s2, lead1, lead2;
		s1 = sNotA[r1] - sNotA[l1 - 1];
		s2 = tNotA[r2] - tNotA[l2 - 1];
		lead1 = min(r1 - l1 + 1, sLeadA[r1]);
		lead2 = min(r2 - l2 + 1, tLeadA[r2]);
		if (s1 == 0 && s2 != 0) {
			if (lead1 <= lead2) {
				putchar('0');
				continue;
			}
			lead1 -= (lead1 - lead2) % 3;
			s1 += 2;
		}
		if (lead1 < lead2) {
			putchar('0');
			continue;
		}
		if ((lead1 - lead2) % 3 != 0)
			s1 += 2;
		if (s1 > s2 || (s2 - s1) % 2 != 0) {
			putchar('0');
		} else
			putchar('1');
	}
	return 0;
}