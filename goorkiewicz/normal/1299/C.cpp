#include <bits/stdc++.h>
using namespace std;
typedef long double lf;
#define f first
#define s second

const lf inf = 1000000005.0;
const int N = 1000005;
int n, i, j, l;
lf s;
lf t [N];
lf out [N];
pair <lf, int> p, q;
vector < pair <lf,int> > vec;

int main ()
	{
	scanf ("%d", &n);
	
	for (i=1; i<=n; i++)
		scanf ("%Lf", &t[i]);
	
	reverse(t+1, t+n+1);

	vec.push_back({inf, 0});
	
	for (i=1; i<=n; i++)
		{
		p = {t[i], 1};
		
		while (vec.back().f < p.f)
			{
			q = vec.back();
			vec.pop_back();
			
			s = q.f * q.s + p.f * p.s;
			
			p.s = p.s + q.s;
			p.f = s / (lf)(p.s);
			}

		vec.push_back(p);
		}
	
	reverse(vec.begin(), vec.end());
	vec.pop_back();

	i = 1;
	for (pair <lf, int> p : vec)
		while (p.s--)
			out[i++] = p.f;
	
	for (i=1; i<=n; i++)
		printf ("%.13Lf\n", out[i]);
	
	return 0;
	}