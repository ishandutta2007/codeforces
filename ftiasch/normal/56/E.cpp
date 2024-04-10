// Codeforces Beta Round #55
// Problem E -- Domino Principle
#include <cstdio>
#include <cstring>
#include <climits>
#include <utility>
#include <algorithm>

#define N 100001

using namespace std;

int n, x[N], h[N], a[N];
pair<int, int> l[N];

int s, k[N], v[N], p[N], o[N], c[N][2];

void update(int x)
{
	o[x] = max(v[x], max(o[c[x][0]], o[c[x][1]]));
}

void rotate(int &x, int t)
{
	int y = c[x][t];
	c[x][t] = c[y][1 - t];
	c[y][1 - t] = x;
	update(x);
	update(y);
	x = y;
}

void insert(int &x, int kk, int vv)
{
	if(!x)
		k[s] = kk, v[s] = vv, p[s]= rand(), x = s ++;
	else
	{
		int t = kk < k[x]? 0: 1;
		insert(c[x][t], kk, vv);
		if(p[c[x][t]] < p[x])
			rotate(x, t);
	}
	update(x);	
}

int find(int x, int kk)
{
	if(!x)
		return INT_MIN;
	if(k[x] <= kk)
		return max(max(o[c[x][0]], v[x]), find(c[x][1], kk));
	return find(c[x][0], kk);
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i != n; ++ i)
	{
		scanf("%d%d", x + i, h + i);
		l[i] = make_pair(x[i], i);
	}
	sort(l, l + n);	
	s = 1;
	memset(c, 0, sizeof(c));
	o[0] = INT_MIN;
	p[0] = INT_MAX;
	int r = 0;
	for(int i = n - 1; i != -1; -- i)
	{
		int ind = l[i].second;
		int tmp = max(i, find(r, x[ind] + h[ind] - 1));
		insert(r, x[ind], tmp);
		a[ind] = tmp - i + 1;
	}
	for(int i = 0; i != n; ++ i)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}