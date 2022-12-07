#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second

const ll inf = 1000000000000000005;
const int M = (1<<20);
const int N = 1000005;
int n, m, p, i;
ll tree [M+M];
ll lazy [M+M];
vector < pair <int,ll> > v [N];
vector < pair <int,ll> > tmp, a, b;
vector < pair <int,ll> >::iterator it;

void propagate (int u)
	{
	if (lazy[u] == 0)
		return;
	tree[u] += lazy[u];
	if (u < M)
		{
		lazy[u+u+0] += lazy[u];
		lazy[u+u+1] += lazy[u];
		}
	lazy[u] = 0;
	}

void add (int da, int db, ll v, int u = 1, int na = 0, int nb = M)
	{
	propagate(u);
	
	if(na>=nb || na>=db || da>=nb)
		return;
	
	if (da<=na && db>=nb)
		{
		lazy[u] += v;
		propagate(u);
		return;
		}
	
	int m = (na+nb)/2;
	add(da, db, v, u+u+0, na, m);
	add(da, db, v, u+u+1, m, nb);
	tree[u] = max(tree[u+u+0], tree[u+u+1]);
	return;
	}

int main ()
	{
	scanf ("%d%d%d", &n, &m, &p);
	
	tmp = vector < pair <int,ll> > (n);
	for (pair <int,ll>& p : tmp)
		scanf ("%d%lld", &p.f, &p.s);
	sort(tmp.begin(), tmp.end());
	for (pair <int,ll>& p : tmp)
		{
		while (!a.empty() && a.back().s >= p.s)
			a.pop_back();
		a.push_back(p);
		}

	tmp = vector < pair <int,ll> > (m);
	for (pair <int,ll>& p : tmp)
		scanf ("%d%lld", &p.f, &p.s);
	sort(tmp.begin(), tmp.end());
	for (pair <int,ll>& p : tmp)
		{
		while (!b.empty() && b.back().s >= p.s)
			b.pop_back();
		b.push_back(p);
		}

	ll c;
	int y, x;
	while (p--)
		{
		scanf ("%d%d%lld", &x, &y, &c);
		v[x].push_back({y, c});
		}

	add(0, b[0].f, -b[0].s);

	for (i=1; i<b.size(); i++)
		add(b[i-1].f, b[i].f, -b[i].s);
	
	add(b.back().f, M, -inf);
	
	ll out = - a[0].s - b[0].s;
	
	for (x=1; x<N; x++)
		{
		sort(v[x].begin(), v[x].end());
		for (pair <int,ll> p : v[x])
			{
			y = p.f;
			c = p.s;
			add(y, M, c);
			
			propagate(1);
			
			ll profit = tree[1];
			
			it = upper_bound(a.begin(), a.end(), make_pair(x, inf));
			if (it == a.end())
				continue;

			profit -= (*it).s;
			
			out = max(out, profit);
			}
		}

	printf ("%lld\n", out);
	return 0;
	}