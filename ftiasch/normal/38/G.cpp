// School Personal Contest #1
// Problem G -- Queue
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

#define N 100001

using namespace std;

int n, a[N], b[N];
int size, p[N], s[N], o[N], c[N][2];

void update(int x)
{
	s[x] = s[c[x][0]] + s[c[x][1]] + 1;
	o[x] = max(max(o[c[x][0]], o[c[x][1]]), a[x]);
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

void insert(int &x, int i)
{
	if(x)
	{
		int t = 0;
		if(max(a[x], o[c[x][1]]) <= a[i] && 1 + s[c[x][1]] <= b[i])
			b[i] -= 1 + s[c[x][1]], insert(c[x][0], i);
		else
			t = 1, insert(c[x][1], i);
		if(p[c[x][t]] < p[x])
			rotate(x, t);
	}
	else
		p[x = i] = rand();
	update(x);
}

void output(int x)
{
	if(x)
	{
		output(c[x][0]);
		printf("%d ", x);
		output(c[x][1]);
	}
}

int main()
{
	scanf("%d", &n);
	int root = size = 0;
	memset(c, 0, sizeof(c));
	p[0] = INT_MAX, s[0] = 0, o[0] = INT_MIN;
	for(int i = 1; i <= n; ++ i)
		scanf("%d%d", a + i, b + i), insert(root, i);
	output(root);
	printf("\n");
	return 0;
}