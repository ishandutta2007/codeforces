#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <random>
#include <limits>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 200010;

int n, m, q;
int f[N * 2];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
	scanf("%d%d%d", &n, &m, &q);
	iota(f + 1, f + n + m + 1, 1);
	int cnt = n + m - 1;
	while (q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		b += n;
		a = find(a);
		b = find(b);
		if (a != b) {
			f[a] = b;
			--cnt;
		}
	}
	printf("%d\n", cnt);
	return 0;
}