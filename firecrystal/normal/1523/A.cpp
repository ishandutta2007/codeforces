#include <iostream>
#include <cstdio>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

const int N = 1e3 + 5;

int n, m, pr[N], sf[N];

char s[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%s", &n, &m, s + 1);
		for (int i = 1; i <= n; i++) {
			if (s[i] == '1') pr[i] = i;
			else pr[i] = pr[i - 1];
		}
		for (int i = n; i; i--) {
			if (s[i] == '1') sf[i] = i;
			else sf[i] = sf[i + 1];
		}
		for (int i = 1; i <= n; i++) {
			if (s[i] == '1') putchar('1');
			else {
				if (pr[i] || sf[i]) {
					if (pr[i] && sf[i]) {
						int mnd = min(abs(i - pr[i]), abs(sf[i] - i));
						if (abs(i - pr[i]) == abs(sf[i] - i)) putchar('0');
						else if (mnd <= m) putchar('1');
						else putchar('0');
					} else {
						if (sf[i] && abs(sf[i] - i) <= m) putchar('1');
						else if (pr[i] && abs(i - pr[i]) <= m) putchar('1');
						else putchar('0');
					}
				} else {
					putchar('0');
				}
				
			}
		}
		puts("");
		for (int i = 1; i <= n + 1; i++) pr[i] = sf[i] = 0;
	}
	return 0;
}