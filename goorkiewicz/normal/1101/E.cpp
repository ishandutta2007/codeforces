#include <bits/stdc++.h>
using namespace std;

int q, a, b;
char c;
set <int> set1, set2;

int main ()
	{
	scanf ("%d",&q);
	while (q--)
		{
		scanf (" %c %d%d",&c,&a,&b);
		if (b>a)
			swap(a,b);
		if (c=='+')
			{
			set1.insert(a);
			set2.insert(b);
			}
		if (c=='?')
			printf ("%s\n",set1.upper_bound(a)==set1.end() && set2.upper_bound(b)==set2.end() ? "YES" : "NO");
		}
	return 0;
	}