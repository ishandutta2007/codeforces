#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)
#define MAXN 3000
#define MAXMASK ((MAXN + 64-1)/64)
#define MAXE (MAXN*(MAXN-1)/2)

typedef long long lint;
typedef unsigned long long ulint;
typedef unsigned int uint;

using namespace std;

int x[MAXN], y[MAXN];

struct edge {
	union {
		struct {
			uint a:16;
			uint b:16;
			uint dist; /* Little endian */
		};
		ulint v;
	};
	
	edge () {}
	edge (int dist, int a, int b): dist(dist), a(a), b(b) {}
	inline bool operator < (const edge& other) const {return v < other.v;}
} edges[MAXE];

ulint mask[MAXN][MAXMASK];

int main(int argc, char ** argv)
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);

	int ne = 0;
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			edges[ne++] = edge((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]), i, j);

	sort(edges, edges+ne);

	const int nmask = (n + 64-1)/64;

//	for (int i = 0; i < n; i++)
//		for (int k = 0; k < nmask; k++)
//			mask[i][k] = 0;
	
	int result = 0;

	for (int e = ne-1; e >= 0; e--) {
		const edge ed = edges[e];
		int k;

		for (k = 0; k < nmask; k++)
			if (mask[ed.a][k] & mask[ed.b][k])
				break;
		if (k < nmask) {
			result = ed.dist;
			break;
		}

		mask[ed.a][ed.b/64] |= (1ULL << (ed.b%64));
		mask[ed.b][ed.a/64] |= (1ULL << (ed.a%64));
	}

	double radius = sqrt(result) / 2.0;

	printf("%.20f\n", radius);

	return 0;
}