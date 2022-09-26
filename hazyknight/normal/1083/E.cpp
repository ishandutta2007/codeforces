#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double db;

inline char gc()
{
	static char buf[262144],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,262144,stdin),p1 == p2) ? EOF : *p1++;
}

inline void read(int &v)
{
	v = 0;
	char c = gc();
	while (c < '0' || c > '9')
		c = gc();
	while (c >= '0' && c <= '9')
	{
		v = v * 10 + c - '0';
		c = gc();
	}
}

inline void read(ll &v)
{
	v = 0;
	char c = gc();
	while (c < '0' || c > '9')
		c = gc();
	while (c >= '0' && c <= '9')
	{
		v = v * 10 + c - '0';
		c = gc();
	}
}

const int MAXN = 1000005;

struct Rect
{
	ll x,y,a;
	bool operator < (const Rect &p)const
	{
		return x < p.x;
	}
}r[MAXN];

int n,head,tail;
int Q[MAXN];

ll ans;
ll k[MAXN];
ll b[MAXN];

int main()
{
	read(n);
	for (int i = 1;i <= n;i++)
		read(r[i].x),read(r[i].y),read(r[i].a);
	sort(r + 1,r + n + 1);
	Q[head = tail = 1] = 0;
	for (int i = 1;i <= n;i++)
	{
		while (head < tail && k[Q[head]] * r[i].y + b[Q[head]] <= k[Q[head + 1]] * r[i].y + b[Q[head + 1]])
			head++;
		k[i] = -r[i].x;
		ans = max(ans,b[i] = k[Q[head]] * r[i].y + b[Q[head]] + r[i].x * r[i].y - r[i].a);
		while (head < tail && (db)(b[Q[tail]] - b[Q[tail - 1]]) / (k[Q[tail - 1]] - k[Q[tail]]) <= (db)(b[i] - b[Q[tail - 1]]) / (k[Q[tail - 1]] - k[i]))
			tail--;
		Q[++tail] = i;
	}
	cout << ans << endl;
	return 0;
}