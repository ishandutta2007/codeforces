#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, i, A, x, sum, sa;
vector <int> out;

int main ()
	{
	scanf ("%d",&n);
	scanf ("%d",&A);
	out.push_back(1);
	sum+=A;
	sa+=A;
	for (i=2; i<=n; i++)
		{
		scanf ("%d",&x);
		sum+=x;
		if (x*2<=A)
			{
			sa+=x;
			out.push_back(i);
			}
		}
	if (sa*2>sum)
		{
		printf ("%d\n",out.size());
		for (int x : out)
			printf ("%d ",x);
		printf ("\n");
		return 0;
		}
	printf ("0\n");
	return 0;
	}