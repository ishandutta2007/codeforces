#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int M = (1<<19);
int q, n, m, i, j, k, out;
int t [N];
int lel [N];
int tree [M+M];
vector <int> v [N];
map <int,int> Map;
multiset <int> S;

void update (int u, int v)
	{
	u += m;
	tree[u] = min(tree[u], v);
	for (u/=2; u!=0; u/=2)
		tree[u] = min(tree[u+u], tree[u+u+1]);
	}

int query (int a, int b)
	{
	if (a>b) return 0;
	
	a+=m;
	b+=m;
	
	int res = min(tree[a], tree[b]);
	while (a/2 != b/2)
		{
		if (a%2==0) res = min(res, tree[a+1]);
		if (b%2==1) res = min(res, tree[b-1]);
		a/=2;
		b/=2;
		}
	return res;
	}

int main ()
	{
	scanf ("%d",&q);
	while (q--)
		{
		scanf ("%d",&n);
		
		m = 16;
		while (m<=n)
			m *= 2;
		
		for (i=1; i<=n; i++)
			v[i].clear();
		
		Map.clear();
		for (i=1; i<=n; i++)
			{
			scanf ("%d",&t[i]);
			Map[t[i]] = 1;
			}
		
		j = 1;
		for (pair <int,int> P : Map)
			Map[P.first] = j++;

		k = j-1;
		for (i=1; i<=n; i++)
			t[i] = Map[t[i]];

		for (i=1; i<=n; i++)
			v[t[i]].push_back(i);

		S.clear();
		
		for (i=0; i<m+m; i++)
			tree[i] = k+1;
		
		for (i=k; i>=1; i--)
			{
			lel[i] = query(1, v[i].back());
			S.insert(lel[i]);
			for (int x : v[i])
				update(x, i);
			}
		
		out = N;
		for (i=1; i<=k; i++)
			{
			//printf ("i=%d ss=%d\n",i,S.size());
			//for (int a : S)
			//	printf ("%d ",a);
			//printf ("--\n");
			out = min(out, i+k-(*S.begin()));
			S.erase(S.find(lel[i]));
			}
		
		//printf ("cnt = %d out = %d\n",cnt,out);
		printf ("%d\n",out);
		}

	return 0;
	}