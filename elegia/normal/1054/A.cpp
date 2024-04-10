#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;



int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif
	
	int x, y, z, t1, t2, t3;
	scanf("%d%d%d%d%d%d", &x, &y, &z, &t1, &t2, &t3);
	int a1 = abs(x - y) * t1, a2 = (abs(x - z) + abs(x - y)) * t2 + t3 * 3;
	puts(a2 <= a1 ? "YES" : "NO");
	
#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}