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

#define INF (INT_MAX/3)

typedef long long lint;

using namespace std;

pair <lint, lint> egcd(lint a, lint b)
{
	if (a == 0) return make_pair(0, 1);
	pair <lint, lint> res = egcd(b%a, a);
	return make_pair(res.second - (b/a) * res.first, res.first);
}

lint inv(lint a, lint m)
{
	lint ret = (egcd(a, m).first%m+m)%m;
	return ret;
}

pair <lint, lint> solve2(lint inva, lint n, lint p)
{
	lint gs, nback;

	if (inva == 1 || n == p) {
		gs = nback = 0;
	} else if (inva <= n) {
		lint a = inv(inva, p);
		lint y, x, y2;
		
		x = n;
		y = a * x % p;
		
		gs = 1 + ((p-1-x)/inva);
		y2 = y + gs;

		if (y2 >= p) {
			if (n+1 < p) {
				x = n+1;
				y = a * x % p;
				gs = 1 + ((p-1-x)/inva);
				y2 = y + gs;
			} else {
				gs = 0;
			}
		}

		nback = 0;
	} else {
		lint q = p / inva, r = p % inva;
		pair <lint, lint> ret2 = solve2(inva - r, n, inva);

		lint gs2 = ret2.first, nback2 = ret2.second;

		gs = (gs2 + 1)*q - (nback2 + (gs2 != 0)) + gs2;
		nback = gs2;
	}

	return make_pair(gs, nback);
}

bool solve(int a, int n, int p, int h)
{
	return solve2(inv(a%p, p), n+1, p).first + 1 <= h;
}

int main(int argc, char ** argv)
{
	int ntest;

	scanf("%d", &ntest);
	
	for (int t = 0; t < ntest; t++) {
		int a, n, p, h;

		scanf("%d %d %d %d", &a, &n, &p, &h);

		printf(solve(a,n,p,h) ? "YES\n" : "NO\n");
	}

	return 0;
}