#include <cstdlib>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 110;

int n;
int perm[4];
int a[4][N][N];
int b[N * 2][N * 2];
char s[N];

int main() {
	scanf("%d", &n);
	iota(perm, perm + 4, 0);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < n; ++j) {
			gets(s);
			while (s[0] != '0' && s[0] != '1')
				gets(s);
			for (int k = 0; k < n; ++k)
				a[i][j][k] = s[k] == '1';
		}
	}
	int ans = n * n * 4;
	do {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				b[i][j] = a[perm[0]][i][j];
				b[i + n][j] = a[perm[1]][i][j];
				b[i][j + n] = a[perm[2]][i][j];
				b[i + n][j + n] = a[perm[3]][i][j];
			}
		int cur = 0;
		for (int i = 0; i < n * 2; ++i)
			for (int j = 0; j < n * 2; ++j)
				cur += 1 & ((i ^ j) ^ b[i][j]);
		ans = min(ans, min(cur, n * n * 4 - cur));
	} while (next_permutation(perm, perm + 4));
	printf("%d\n", ans);
	return 0;
}