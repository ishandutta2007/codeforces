#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second

const int inf = 1000000005;
int n, i, j;
pair <int,int> m;
vector < pair <int,int> > a, b;

int main ()
	{
	scanf ("%d", &n);
	a.resize(n);
	for (pair <int,int>& p : a)
		scanf ("%d%d", &p.x, &p.y);

	b = a;
	for (pair <int,int>& p : b)
		{
		p.x = -p.x;
		p.y = -p.y;
		}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	m = {inf, inf};
	for (pair <int,int>& p : a)
		m = min(m, p);
	for (pair <int,int>& p : a)
		{
		p.x -= m.x;
		p.y -= m.y;
		}
	
	m = {inf, inf};
	for (pair <int,int>& p : b)
		m = min(m, p);
	for (pair <int,int>& p : b)
		{
		p.x -= m.x;
		p.y -= m.y;
		}

	printf ("%s\n", a == b ? "YES" : "NO");
	return 0;
	}