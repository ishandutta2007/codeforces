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
#define fi first
#define se second
using namespace std;
const int oo = 1000111222;

int m, n, V, H;
pair < int, pair<int,int> > v[200200], h[200200];
set <int> hasX, hasY;
map <int,int> vc, hc;

void traceV(int X, int need)
{
	vector < pair<int,int> > a;
	for (int i = 0; i < V; i++)
		if (v[i].fi == X) a.push_back(v[i].se);
	a.push_back(make_pair(n, n));
	int last = 0;
	for (int i = 0; i < int(a.size()); i++)
		if (a[i].se > last)
		{
			if (a[i].fi > last)
			{
				if (need <= a[i].fi - last)
				{
					cout << X << ' ' << 0 << ' ' << X << ' ' << need + last;
					exit(0);
				}
				need -= a[i].fi - last;
			}
			last = a[i].se;
		}
}

void traceH(int Y, int need)
{
	vector < pair<int,int> > a;
	for (int i = 0; i < H; i++)
		if (h[i].fi == Y) a.push_back(h[i].se);
	a.push_back(make_pair(m, m));
	int last = 0;
	for (int i = 0; i < int(a.size()); i++)
		if (a[i].se > last)
		{
			if (a[i].fi > last)
			{
				if (need <= a[i].fi - last)
				{
					cout << 0 << ' ' << Y << ' ' << need + last << ' ' << Y << endl;
					exit(0);
				}
				need -= a[i].fi - last;
			}
			last = a[i].se;
		}
}

int main()
{
	//freopen("c.in","r",stdin);
	int k, x, y, xx, yy;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		scanf("%d%d%d%d", &x, &y, &xx, &yy);
		if (x == xx) v[V++] = make_pair(x, make_pair(min(y, yy), max(y, yy)));
		else h[H++] = make_pair(y, make_pair(min(x, xx), max(x, xx)));
	}
	
	int sumXor = 0;
	
	sort(v, v + V);
	int lastY = 0, cnt = 0;
	for (int i = 0; i < V; i++)
	{
		x = v[i].fi; y = v[i].se.fi; yy = v[i].se.se;
		hasX.insert(x);
		if (i && x != v[i - 1].fi) vc[v[i - 1].fi] = cnt, sumXor ^= (n - cnt), cnt = lastY = 0;
		if (yy >= lastY) cnt += yy - max(y, lastY);
		lastY = max(lastY, yy);
	}
	if (V) sumXor ^= (n - cnt), vc[x] = cnt;
	
	sort(h, h + H);
	int lastX = 0;
	cnt = 0;
	for (int i = 0; i < H; i++)
	{
		y = h[i].fi; x = h[i].se.fi; xx = h[i].se.se;
		hasY.insert(y);
		if (i && y != h[i - 1].fi) hc[h[i - 1].fi] = cnt, sumXor ^= (m - cnt), cnt = lastX = 0;
		if (xx >= lastX) cnt += xx - max(x, lastX);
		lastX = max(lastX, xx);
	}
	if (H) sumXor ^= (m - cnt), hc[y] = cnt;
	
	if ((m - 1 - int(hasX.size())) % 2) sumXor ^= n;
	if ((n - 1 - int(hasY.size())) % 2) sumXor ^= m;
	
	if (!sumXor) puts("SECOND");
	else
	{
		puts("FIRST");
		for (int x = 1; x < m; x++)
			if (!hasX.count(x))
			{
				int t = sumXor ^ n;
				if (t <= n) traceV(x, n - t);
				break;
			}
				
		for (int y = 1; y < n; y++)
			if (!hasY.count(y))
			{
				int t = sumXor ^ m;
				if (t <= m) traceH(y, m - t);
				break;
			}
				
		for (map <int,int>::iterator it = vc.begin(); it != vc.end(); it++)
		{
			int cnt = it -> second, x = it -> first;
			if ((sumXor ^ (n - cnt)) + cnt <= n) traceV(x, n - cnt - (sumXor ^ (n - cnt)));
		}
		
		for (map <int,int>::iterator it = hc.begin(); it != hc.end(); it++)
		{
			int cnt = it -> second, y = it -> first;
			if ((sumXor ^ (m - cnt)) + cnt <= m) traceH(y, m - cnt - (sumXor ^ (m - cnt)));
		}
	}
}