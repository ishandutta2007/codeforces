#include <bits/stdc++.h>
using namespace std;

int q, n, i, j, a, b;
map <int,int> t;
map <int,int>::iterator it, pr;

inline long long up (long long a, long long b) {
	return ((a+a+b+b)*(a+a+b+b));
	}

inline long long dw (long long a, long long b) {
	return (a*b);
	}

int main ()
	{
	scanf ("%d",&q);
	while (q--)
		{
		scanf ("%d",&n);
		a=10001;
		b=1;
		t.clear();
		while (n--)
			{
			scanf ("%d",&i);
			t[i]++;
			}
		j=0;
		for (pair <int,int> p : t)
			if (p.second>=2)
				{
				i=p.first;
				if (p.second>=4)
					if ((up(i,i)*dw(a,b)) < (dw(i,i)*up(a,b)))
						{
						a=i;
						b=i;
						}
				if (j!=0)
					if ((up(i,j)*dw(a,b)) < (dw(i,j)*up(a,b)))
						{
						a=i;
						b=j;
						}
				j=i;
				}
		printf ("%d %d %d %d\n",a,a,b,b);
		}
	return 0;
	}