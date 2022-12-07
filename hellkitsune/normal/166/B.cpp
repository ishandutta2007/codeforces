#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct pt
{
	long long x, y;
};

struct ang
{
	long long a, b;
};

bool operator < (const ang &p, const ang &q) {
	if ((p.b == 0) && (q.b == 0))
		return p.a > q.a;
    if ((p.a == 0) && (q.a == 0))
        return p.b < q.b;
	return p.a * q.b < p.b * q.a;
}

long long square(pt &a, pt &b, pt &c) {
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}

int main(void)
{
    int n, m, i;
	scanf("%d", &n);
	vector<pt> p(n);
	int z = n - 1;
	for (i = n - 1; i >= 0; --i) {
		scanf ("%I64d%I64d", &p[i].x, &p[i].y);
		if ((p[i].x < p[z].x) || ((p[i].x == p[z].x) && (p[i].y < p[z].y)))
			z = i;
	}
	pt zero = p[z];
	rotate (p.begin(), p.begin()+z, p.end());
	p.erase (p.begin());
	--n;
	vector<ang> a(n);
	for (i = 0; i < n; ++i) {
		a[i].a = p[i].y - zero.y;
		a[i].b = p[i].x - zero.x;
		/*if (a[i].a == 0)
			a[i].b = a[i].b < 0 ? -1 : 1;*/
	}
    scanf("%d", &m);
    pt q;
	for (i = 0; i < m; ++i) {
		scanf("%I64d%I64d", &q.x, &q.y);
		bool in = false;
		if (q.x >= zero.x)
			if ((q.x != zero.x) || (q.y != zero.y))
			{
			    ang t = {q.y - zero.y, q.x - zero.x};
				/*if (t.a == 0)
					t.b = t.b < 0 ? -1 : 1;*/
				vector<ang>::iterator it = upper_bound(a.begin(), a.end(), t);
				if ((it == a.end()) && (t.a == a[n - 1].a) && (t.b == a[n - 1].b))
					it = a.end() - 1;
				if (it != a.end() && it != a.begin()) {
					int p1 = int (it - a.begin());
					if (square(p[p1], p[p1 - 1], q) < 0)
						in = true;
				}
			}
		if (!in)
		{
		    printf("NO");
		    return 0;
		}
	}
	printf("YES");
    return 0;
}