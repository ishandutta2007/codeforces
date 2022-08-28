#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 2010;

int n, k;
char s[N][N];
bool vis[N][N];
int sum[N][N];
pair<char, pair<int, int> > qq[N * 2];
pair<int, int> tmp[N * 2];

char ans[N * 2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			if (i > 1)
				if (j > 1)
					sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + (s[i][j] != 'a');
				else
					sum[i][j] = sum[i - 1][j] + (s[i][j] != 'a');
			else
				if (j > 1)
					sum[i][j] = sum[i][j - 1] + (s[i][j] != 'a');
				else
					sum[i][j] = s[i][j] != 'a';
		}
	if (sum[n][n] <= k) {
		memset(ans + 1, 'a', n * 2 - 1);
		puts(ans + 1);
		return 0;
	}
	int a = n * 2;
	for (; a > 1; --a) {
		bool flag = false;
		for (int x = 1; x <= n; ++x) {
			int y = a - x;
			if (y < 1 || y > n)
				continue;
			if (sum[x][y] <= k) {
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}
	for (int i = 1; i < a; ++i)
		ans[i] = 'a';
	int cnt = 0;
	for (int i = 0; i <= n; ++i)
		sum[i][0] = sum[0][i] = k + 1;
	for (int x = 1; x <= n; ++x) {
		int y = a + 1 - x;
		if (y < 1 || y > n)
			continue;
		if (sum[x - 1][y] > k && sum[x][y - 1] > k && (x != 1 || y != 1))
			continue;
		qq[++cnt] = make_pair(s[x][y], make_pair(x, y));
	}
	while (++a <= n * 2) {
		sort(qq + 1, qq + cnt + 1);
		char goal = qq[1].first;
		ans[a - 1] = qq[1].first;
		int c2 = 0;
		for (int i = 1; i <= cnt; ++i)
			if (qq[i].first != goal) {
				break;
			} else
				tmp[++c2] = qq[i].second;
		cnt = 0;
		for (int i = 1; i <= c2; ++i) {
			int x = tmp[i].first, y = tmp[i].second;

			if (x + 1 <= n && !vis[x + 1][y]) {
				qq[++cnt] = make_pair(s[x + 1][y], make_pair(x + 1 , y));
				vis[x + 1][y] = true;
			}
			if (y + 1 <= n && !vis[x][y + 1]) {
				qq[++cnt] = make_pair(s[x][1 +y], make_pair(x , 1+ y));
				vis[x][y + 1] = true;
			}
		}
	}
	puts(ans + 1);

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}