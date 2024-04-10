#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <limits>
#include <numeric>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

const int N = 52;

int n, m;
char s[N][N];
bool f[N], r[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; ++i) {
		bool flag = false;
		for (int j = 1; j <= m; ++j) {
			f[j] = s[i][j] == '#';
			if (!flag && f[j]) {
				for (int k = 1; k <= n; ++k)
					r[k] = s[k][j] == '#';
				flag = true;
			}
		}
		if (!flag)
			continue;
		for (int j = 1; j <= m; ++j)
			for (int k = 1; k <= n; ++k)
				if (f[j] && r[k]) {
					if (s[k][j] == '.') {
						puts("No");
						return 0;
					}
					s[k][j] = '.';
				}
		for (int j = 1; j <= m; ++j)
			if (f[j])
				for (int k = 1; k <= n; ++k)
					if (s[k][j] == '#') {
						puts("No");
						return 0;
					}
		for (int k = 1; k <= n; ++k)
			if (r[k])
				for (int j = 1; j <= m; ++j)
					if (s[k][j] == '#') {
						puts("No");
						return 0;
					}
	}
	puts("Yes");
	return 0;
}