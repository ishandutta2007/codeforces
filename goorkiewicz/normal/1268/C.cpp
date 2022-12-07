#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

const int N = 200005;
const int M = 262144;

struct segtree
	{
	int tree [M+M];
	
	void update (int u, int v) {
		for (u+=M; u>=1; u/=2)
			tree[u] += v;
		}

	int query (int a, int b)
		{
		a += M;
		b += M;
		if (a>b) return 0;
		if (a==b) return tree[a];
		int res = tree[a] + tree[b];
		while (a/2 != b/2)
			{
			if (a%2==0) res += tree[a+1];
			if (b%2==1) res += tree[b-1];
			a /= 2;
			b /= 2;
			}
		return res;
		}
	};

int t [N];
int pos [N];
int n, i, j, k, p, m, r;
ll inv, cost, d;
segtree Z;
tree < int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update > T;

int main ()
	{
	scanf ("%d", &n);
	for (i=1; i<=n; i++)
		{
		scanf ("%d", &t[i]);
		pos[t[i]] = i;
		}
	
	for (k=1; k<=n; k++)
		{
		inv += Z.query(pos[k], n+1);
		Z.update(pos[k], 1);

		p = pos[k];

		T.insert(p);
		
		if (k==1)
			{
			m = p;
			printf ("0 ");
			continue;
			}
		
		i = T.order_of_key(p);
		j = T.order_of_key(m);

	//	printf ("i=%d j=%d\n", i, j);
		
		d = abs(m - p);
		d -= abs(i - j);
		
		cost += d;
		
		if (p>m)
			cost -= k - T.order_of_key(p) - 1;
		if (p<m)
			cost -= T.order_of_key(p);
		
	//	printf ("d=%lld cost=%lld\n", d, cost);
		while (T.order_of_key(m) > k/2)
			{
			r = *T.find_by_order(T.order_of_key(m)-1);
			cost -= abs(m - r - 1);
	//		printf ("%d -> %d\n", m, r);
			m = r;
			}
		while (T.order_of_key(m) < k/2)
			{
			r = *T.find_by_order(T.order_of_key(m)+1);
			if (k%2==1)
				cost -= abs(m - r - 1);
	//		printf ("%d -> %d\n", m, r);
			m = r;
			}
	//	printf ("> cost = %lld\n", cost);
	//	printf ("k=%d m=%d %lld\n", k, m, cost+inv);
		printf ("%lld ", cost+inv);
		}
	printf ("\n");
	return 0;
	}