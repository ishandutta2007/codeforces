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
#define MAXN 20
#define MAXPN (1<<MAXN)

typedef long long lint;

using namespace std;

int v[MAXPN];

lint totinv[MAXN+1][2];
int isinv[MAXN+1];


lint calc(int a, int b, int c, int d)
{
	static int list[MAXPN];
	int n2 = d-c;
	for (int i = 0; i < n2; i++)
		list[i] = v[c + i];
	sort(list, list + n2);
	
	lint ret = 0;
	for (int i = a; i < b; i++)
		ret += lower_bound(list, list+n2, v[i])-list;

	return ret;
}

int main(int argc, char ** argv)
{
	int n;
	scanf("%d", &n);

	const int pn = 1<<n;

	for (int i = 0; i < pn; i++) scanf("%d", &v[i]);

	for (int x = 0; x <= n; x++) {
		totinv[x][0] = totinv[x][1] = 0;
		isinv[x] = 0;
	}

	for (int x = 1; x <= n; x++) {
		const int px = 1<<x;
		for (int l = 0, m = px/2, r = px; r <= pn; l += px, m += px, r += px) {
			totinv[x][0] += calc(l, m, m, r);
			totinv[x][1] += calc(m, r, l, m);
		}
	}

	lint invnow = 0;

	for (int x = 0; x <= n; x++) invnow += totinv[x][0];

	int m;
	scanf("%d", &m);

	for (int q = 0; q < m; q++) {
		int qi;
		scanf("%d", &qi);
		for (int x = 0; x <= qi; x++) {
			invnow += totinv[x][ isinv[x]^1 ] - totinv[x][ isinv[x] ];
			isinv[x] ^= 1;
		}
		printf("%I64d\n", invnow);
	}

	return 0;
}