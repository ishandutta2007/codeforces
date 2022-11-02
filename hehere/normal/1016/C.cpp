#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::sort; using std::min; using std::max;
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <queue>
using std::queue; using std::priority_queue;
#include <utility>
using std::pair;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

const int maxN = 300000 + 233;
int n;
LL a[2][maxN];
LL s[2][maxN], sr[2][maxN];
LL c[2][maxN];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%I64d", &a[0][i]);
	for(int i = 0; i < n; ++i) scanf("%I64d", &a[1][i]);
	memset(s, 0, sizeof(s)); memset(sr, 0, sizeof(sr));
	memset(c, 0, sizeof(c));
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < n; ++j) s[i][j] = s[i][j-1] + a[i][j];
		for(int j = n - 1; j >= 0; --j) sr[i][j] = sr[i][j+1] + a[i][j];
	}
	for(int i = 0; i < 2; ++i) {
		for(int j = n - 1; j >= 0; --j) {
//			if(i == 0 && j == 1) {
//				printf("%lld + %lld + %lld + %lld\n", (sr[0][j + 1] + sr[1][j + 1]), a[i][j], (2LL * (n - 1 - j) + 2LL) * a[i^1][j],
//					c[i][j + 1]);
//			}
			c[i][j] = (sr[0][j + 1] + sr[1][j + 1]) + a[i][j] + (2LL * (n - 1 - j) + 2LL) * a[i^1][j]
				+ c[i][j+1];
		}
	}
//	for(int i = 0; i < 2; ++i) {
//		for(int j = 0; j < n; ++j) printf("%lld ", c[i][j]); printf("\n");
//	}
	LL ans = 0, fix = -1LL * (sr[0][0] + sr[1][0]), cur = 0;
	for(int i = 0; i < n; ++i) {
//		printf("i = %lld, cur = %lld\n", (LL)i, cur);
		ans = max(ans, cur + c[i & 1][i] + fix + 2LL * i * (sr[0][i] + sr[1][i]));
		cur += 2 * i * a[i & 1][i] + (2 * i + 1) * a[(i & 1) ^ 1][i];
		fix += a[0][i] + a[1][i];
	}
	printf("%I64d\n", ans);
	return 0;
}