#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

int d[10010];
int n, m, L, R, Q, b[10010], c[10010], bl[10100], cl[10100], nl, pl[10010], br[10010], cr[10100], pr[10100], nr;

int get(int x)
{
	return x == d[x] ? x : d[x] = get(d[x]);
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++) scanf("%d%d", b + i, c + i);
	
	
	for (int i = 1; i <= n; i++) d[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int x = get(b[i]), y = get(c[i]);
		if (x == y) continue;
		d[x] = y;
		bl[++nl] = b[i]; cl[nl] = c[i]; pl[nl] = i;
	}
	
	for (int i = 1; i <= n; i++) d[i] = i;
	for (int i = m; i; i--)
	{
		int x = get(b[i]), y = get(c[i]);
		if (x == y) continue;
		d[x] = y;
		br[++nr] = b[i]; cr[nr] = c[i]; pr[nr] = i;
	}
	
	cin >> Q;
	while (Q--)
	{
		scanf("%d%d", &L, &R);
		
		for (int i = 1; i <= n; i++) d[i] = i;
		int component = n;
		
		for (int i = 1; i <= nl && pl[i] < L; i++)
		{
			int x = get(bl[i]), y = get(cl[i]);
			if (x == y) continue;
			component--;
			d[x] = y;
		}
		
		for (int i = 1; i <= nr && pr[i] > R; i++)
		{
			int x = get(br[i]), y = get(cr[i]);
			if (x == y) continue;
			component--;
			d[x] = y;
		}
		
		cout << component << endl;
	}
}