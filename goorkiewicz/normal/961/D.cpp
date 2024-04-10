#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> point;
#define x first
#define y second

const point inf = point(1000000001,1000000001);
point p [100001];
int n, i, j;

ll IW (point a, point b, point c)
	{
	a.x-=c.x; a.y-=c.y;
	b.x-=c.x; b.y-=c.y;
	return (a.x*b.y)-(a.y*b.x);
	}

int check (int a, int b)
	{
	point A = p[a];
	point B = p[b];
	point C = inf;
	point D = inf;
	for (i=1; i<=n; i++)
		{
		if (i==a || i==b)
			continue;
		if (IW(p[i],A,B)==0)
			continue;
		if (C==inf)
			{
			C=p[i];
			continue;
			}
		if (D==inf)
			{
			D=p[i];
			continue;
			}
		if (IW(p[i],C,D)!=0)
			return false;
		}
	return true;
	}

int main ()
	{
	scanf ("%d",&n);
	for (i=1; i<=n; i++)
		scanf ("%lld%lld",&p[i].x,&p[i].y);
	if (n<=4)
		return printf ("YES\n"), 0;
	if (check(1,2)) return printf ("YES\n"), 0;
	if (check(1,3)) return printf ("YES\n"), 0;
	if (check(1,4)) return printf ("YES\n"), 0;
	if (check(2,3)) return printf ("YES\n"), 0;
	if (check(2,4)) return printf ("YES\n"), 0;
	if (check(3,4)) return printf ("YES\n"), 0;
	return printf ("NO\n"), 0;
	}