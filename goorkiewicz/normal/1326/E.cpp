#include <bits/stdc++.h>
using namespace std;

const int M = (1<<19);
const int N = 300005;
int n, i, j, out;
int p [N];
int q [N];
int pos [N];
int tree [M+M];
int lazy [M+M];

void propagate (int u)
	{
	tree[u] += lazy[u];
	if (u < M)
		{
		lazy[u+u+0] += lazy[u];
		lazy[u+u+1] += lazy[u];
		}
	lazy[u] = 0;
	}

void update (int da, int db, int v, int u=1, int na=0, int nb=M)
	{
	propagate(u);
	if (na >= db || da >= nb)
		return;
	if (na >= da && nb <= db)
		{
		lazy[u] += v;
		propagate(u);
		return;
		}
	int m = (na+nb)/2;
	update(da, db, v, u+u+0, na, m);
	update(da, db, v, u+u+1, m, nb);
	tree[u] = max(tree[u+u+0], tree[u+u+1]);
	}

int main ()
	{
	scanf ("%d", &n);
	
	for (i=1; i<=n; i++)
		{
		scanf ("%d", &p[i]);
		pos[p[i]] = i;
		}

	for (i=1; i<=n; i++)
		scanf ("%d", &q[i]);
	
	out = n+1;
	for (i=1; i<=n; i++)
		{
		propagate(1);
		
		while (tree[1] <= 0)
			{
			out--;
		//	printf ("update ++ %d\n", pos[out]);
			update(0, pos[out]+1, 1);
			}
		
		printf ("%d ", out);
	//	printf ("update -- %d\n", q[i]);
		update(0, q[i]+1, -1);
		}
	printf ("\n");
	return 0;
	}