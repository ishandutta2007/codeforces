#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int q, n, i, a, m1, m2, cnt;

int main ()
	{
	scanf ("%d",&q);
	while (q--)
		{
		scanf ("%d",&n);
		m1 = 0;
		m2 = 0;
		for (i=0; i<n; i++)
			{
			scanf ("%d",&a);
			if (a>m1)
				{
				m2 = m1;
				m1 = a;
				}
			else if (a>m2)
				m2 = a;
			}
		if (n==2)
			{
			printf ("0\n");
			continue;
			}
		m2--;
		printf ("%d\n",min(m2,n-2));
		}
	return 0;
	}