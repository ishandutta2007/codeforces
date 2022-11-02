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
#include <cstdlib>
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

const int maxN = 100 + 5;
int n, m, a[maxN], b[maxN], c[maxN][maxN], r[maxN][maxN];

void nosol() {
	printf("NO\n");
	exit(0);
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= m; ++i) cin >> b[i];
	memset(c, 0, sizeof(c)); memset(r, 0, sizeof(r));
	for(int k = 1; 1; k <<= 1) {
		memset(c, 0, sizeof(c));
		for(int i = 1; i <= n; ++i) if(a[i] & k) {
			for(int j = 1; j <= m; ++j) if(b[j] & k) {
				c[i][j] = k; a[i] ^= k; b[j] ^= k;
				break;
			}
		}
		for(int i = 1; i <= n; ++i) if(!(a[i] & k)) {
			BEGIN:
			for(int x = 1; x <= m; ++x) if(!c[i][x] && (b[x] & k)) {
//				printf("i = %d, x = %d, y = ??\n", i, x);
				for(int y = x + 1; y <= m; ++y) if(/*printf("%d %d\n", c[i][y], b[y]),*/ !c[i][y] && (b[y] & k)) {
					
					c[i][x] = c[i][y] = k;
					b[x] ^= k; b[y] ^= k;
					goto BEGIN;
				}
			}
		}
		for(int j = 1; j <= m; ++j) if(!(b[j] & k)) {
			BEGIN2:
			for(int x = 1; x <= n; ++x) if(!c[x][j] && (a[x] & k)) {
				for(int y = x + 1; y <= n; ++y) if(!c[y][j] && (a[y] & k)) {
					c[x][j] = c[y][j] = k;
					a[x] ^= k; a[y] ^= k;
					goto BEGIN2;
				}
			}
		}
		for(int i = 1; i <= n; ++i) if(a[i] & k) nosol();
		for(int j = 1; j <= m; ++j) if(b[j] & k) nosol();
		
		for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j)
			r[i][j] |= c[i][j];
		if(k == 1073741824) break;
	}
	printf("YES\n");
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) printf("%d ", r[i][j]);
		printf("\n");
	}
	return 0;
}