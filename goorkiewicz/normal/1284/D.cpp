#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

const int M = (1<<19);
int tree [M+M];
int lazy [M+M];

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

void add (int u, int na, int nb, int da, int db)
	{
	propagate(u);
	
	if(na>=nb || na>=db || da>=nb)
		return;
	
	if (da<=na && db>=nb)
		{
		lazy[u]++;
		propagate(u);
		return;
		}
	
	int m = (na+nb)/2;
	add (u+u+0, na, m, da, db);
	add (u+u+1, m, nb, da, db);
	tree[u] = max(tree[u+u+0], tree[u+u+1]);
	return;
	}

int query (int u, int na, int nb, int da, int db)
	{
	propagate(u);
	
	if(na>=nb || na>=db || da>=nb)
		return 0;
	
	if (da<=na && db>=nb)
		return tree[u];

	int m = (na+nb)/2;
	return max(
	query(u+u+0, na, m, da, db),
	query(u+u+1, m, nb, da, db));
	}

const int N = 100005;
const int K = 400005;
int n, i, pre;
int ax [N+5];
int ay [N+5];
int bx [N+5];
int by [N+5];
vector < pair <int,int> > A [K+5];
vector < pair <int,int> > Q [K+5];
map <int,int> Map;

bool solve (int* ax, int* ay, int* bx, int* by)
	{
	for (i=0; i<=K; i++)
		{
		A[i].clear();
		Q[i].clear();
		}
	for (i=0; i<M+M; i++)
		{
		tree[i] = 0;
		lazy[i] = 0;
		}
	for (i=1; i<=n; i++)
		{
		A[ay[i]].push_back({bx[i], by[i]});
		Q[ax[i]].push_back({bx[i], by[i]});
		}
	for (i=0; i<=K; i++)
		{
		while (!Q[i].empty())
			{
			if (query(1, 0, M, Q[i].back().f, Q[i].back().s+1) > 0)
				return true;
			Q[i].pop_back();
			}
		while (!A[i].empty())
			{
			add(1, 0, M, A[i].back().f, A[i].back().s+1);
			A[i].pop_back();
			}
		}
	return false;
	}

int main ()
	{
	scanf ("%d", &n);
	
	for (i=1; i<=n; i++)
		{
		scanf ("%d%d%d%d", &ax[i], &ay[i], &bx[i], &by[i]);
		Map[ax[i]] = 1;
		Map[ay[i]] = 1;
		Map[bx[i]] = 1;
		Map[by[i]] = 1;
		}
	
	i = 0;
	pre = -1;
	for (pair <int,int> p : Map)
		{
		if (p.f != pre) i++;
		Map[p.f] = i;
		}

	for (i=1; i<=n; i++)
		{
		ax[i] = Map[ax[i]];
		ay[i] = Map[ay[i]];
		bx[i] = Map[bx[i]];
		by[i] = Map[by[i]];
		}
	
	if (solve(ax, ay, bx, by) == true)
		return printf ("NO\n"), 0;
	
	if (solve(bx, by, ax, ay) == true)
		return printf ("NO\n"), 0;
	
	printf ("YES\n");
	return 0;
	}