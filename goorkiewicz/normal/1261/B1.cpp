#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define f first
#define s second

const int M = 200005;
int q, n, i, j, k;
int out [M];
vector < pair <int,int> > E;
vector < pair < pair <int,int> , int > > Q;
tree < pair <int,int> , null_type, less < pair <int,int> > , rb_tree_tag, tree_order_statistics_node_update> seq;

int main ()
	{
	scanf ("%d", &n);

	for (i=1; i<=n; i++)
		{
		int a;
		scanf ("%d", &a);
		E.push_back({a, i});
		}
	
	sort(E.begin(), E.end(), [] (pair <int,int> a, pair <int,int> b) {
		if (a.f != b.f)
			return a.f > b.f;
		return a.s < b.s;
		});
	
	scanf ("%d", &q);
	for (i=1; i<=q; i++)
		{
		int a, b;
		scanf ("%d%d", &a, &b); 
		Q.push_back({{a, b}, i});
		}

	sort(Q.begin(), Q.end());
	reverse(Q.begin(), Q.end());

	for (k=1; k<=n; k++)
		{
		seq.insert({E[k-1].s, E[k-1].f});
		while (!Q.empty() && Q.back().f.f == k)
			{
			out[Q.back().s] = (*seq.find_by_order(Q.back().f.s-1)).s;
			Q.pop_back();
			}
		}

	for (i=1; i<=q; i++)
		printf ("%d\n", out[i]);

	return 0;
	}