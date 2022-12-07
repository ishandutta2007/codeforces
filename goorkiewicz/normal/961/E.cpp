#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int p = 262144;
int n, i, j;
ll out;
int e [200001];
vector < pair<int,int> > eve;
int tree [p+p+1];

inline void add (int u)
	{
	u+=p;
	tree[u]++;
	for (u/=2; u!=0; u/=2)
		tree[u]++;
	}

inline int sum (int a, int b)
	{
	a+=p;
	b+=p;
	int res = tree[a];
	if (a!=b)
		res+=tree[b];
	while (a/2!=b/2)
		{
		if (a%2==0)
			res+=tree[a+1];
		if (b%2==1)
			res+=tree[b-1];
		a/=2;
		b/=2;
		}
	return res;
	}

int main ()
	{
	scanf ("%d",&n);
	for (i=1; i<=n; i++)
		{
		scanf ("%d",&e[i]);
		if (e[i]>=i)
			out--;
		eve.push_back({e[i],i});
		}
	sort(eve.begin(), eve.end());
	for (i=n; i>=1; i--)
		{
		while (!eve.empty() && eve.back().first>=i)
			{
			add(eve.back().second);
			eve.pop_back();
			}
		out+=(ll)(sum(1,min(n,e[i])));
		}
	printf ("%lld\n",out/2);
	return 0;
	}