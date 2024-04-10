#include <cmath>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

const int N = 2010;

char mp[N][N];
int mxc[N][N], mxr[N][N];

int main() {
	int n, m, k, cnt = 0;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%s", mp[i] + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (mp[i][j] == '*')
				continue;
			mxc[i][j] = mxc[i][j - 1] + 1;
			mxr[i][j] = mxr[i - 1][j] + 1;
			if (mxc[i][j] >= k)
				++cnt;
			if (mxr[i][j] >= k)
				++cnt;
		}
	printf("%d\n", k == 1 ? cnt / 2 : cnt);
	return 0;
}