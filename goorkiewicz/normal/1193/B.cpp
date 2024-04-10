#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 1000000001;
const int N = 100002;
int n, m, k, i, j;
ll out;
int t [N];
int c [N];
int s [N];
vector <int> e [N];
multiset < pair <int,int> > F [N];
multiset < pair <int,int> >::iterator it;

void dfs (int u)
	{
	s[u] = 1;
	if (e[u].empty())
		{
		if (c[u]!=0)
			F[u].insert({t[u], c[u]});
		return;
		}
	int f = e[u][0];
	for (int v : e[u])
		{
		dfs(v);
		s[u]+=s[v];
		if (s[v]>s[f])
			f = v;
		}
	F[u] = move(F[f]);
	for (int v : e[u])
		for (pair <int,int> d : F[v])
			F[u].insert(d);
	if (c[u]==0)
		return;
	ll sum = 0;
	F[u].insert({t[u], c[u]});
	pair <int,int> d;
	while (true)
		{
		it = F[u].upper_bound({t[u], inf});
		if (it==F[u].end()) break;
		d = (*it);
		sum += d.second;
		F[u].erase(it);
		if (sum>c[u])
			{
			F[u].insert({d.first, sum-c[u]});
			break;
			}
		}
	}

int main ()
	{
	scanf ("%d%d%d",&n,&m,&k);
	for (i=2; i<=n; i++)
		{
		scanf ("%d",&j);
		e[j].push_back(i);
		}
	while (m--)
		{
		scanf ("%d",&i);
		scanf ("%d%d",&t[i],&c[i]);
		}
	
	dfs(1);
	for (pair <int,int> d : F[1])
		out+=d.second;
	printf ("%lld\n",out);
	return 0;
	}