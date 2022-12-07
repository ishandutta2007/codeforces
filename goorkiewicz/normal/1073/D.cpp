#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int p = 262144;
int n, i, k;
ll x, out;
ll tree [2*p+2];

inline void Find (ll s)
	{
	i=1;
	while (i<p)
		{
		if (tree[i+i]>s)
			i=i+i;
		else
			{
			s-=tree[i+i];
			i=i+i+1;
			}
		}
	}

int main ()
	{
	scanf ("%d%lld",&n,&x);
	k=n;
	for (i=1; i<=n; i++)
		scanf ("%lld",&tree[i+p]);
	for (i=p-1; i!=0; i--)
		tree[i]=tree[i+i]+tree[i+i+1];
	while (tree[1]!=0)
		{
		out+=((x/tree[1])*(ll)(k));
		x%=tree[1];
		while (tree[1]>x)
			{
			Find(x);
			tree[i]=0;
			k--;
			for (i/=2; i!=0; i/=2)
				tree[i]=tree[i+i]+tree[i+i+1];
			}
		}
	printf ("%lld\n",out);
	return 0;
	}