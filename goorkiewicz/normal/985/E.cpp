#include <bits/stdc++.h>
using namespace std;

const int p = 524288;
int n, k, d, i, j, h;
int t [500005];
bool tree [(2*p)+1];

bool Query (int left, int right)
	{
	left+=p;
	right+=p;
	if (left>right)
		return false;
	bool res = (tree[left]|tree[right]);
	while (left/2!=right/2)
		{
		if (left%2==0)
			res|=tree[left+1];
		if (right%2==1)
			res|=tree[right-1];
		left/=2;
		right/=2;
		}
	return res;
	}

int main ()
	{
	scanf ("%d%d%d",&n,&k,&d);
	for (i=1; i<=n; i++)
		scanf ("%d",&t[i]);
	t[n+1]=1000000001;
	sort (t+1,t+n+1);
	j=0;
	for (h=p; h!=0; h/=2)
		tree[h]=true;
	for (i=k; i<=n; i++)
		{
		while (t[i]-t[j+1]>d)
			j++;
		if (Query(j,i-k)==true)
			for (h=(i+p); h!=0; h/=2)
				tree[h]=true;
		}
	if (tree[p+n]==true)
		printf ("YES\n");
	else
		printf ("NO\n");
	return 0;
	}