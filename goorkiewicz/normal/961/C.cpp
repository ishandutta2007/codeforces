#include <bits/stdc++.h>
using namespace std;

int n, k, y, x, i, j, out=1000000001;
char c [5][101][101];
int dis1 [5];
int dis2 [5];

inline void check (int a, int b)
	{
	int res = 0;
	for (k=1; k<=4; k++)
		{
		if (k==a || k==b)
			res+=dis1[k];
		else
			res+=dis2[k];
		}
	out=min(out,res);
	}

int main ()
	{
	scanf ("%d",&n);
	for (k=1; k<=4; k++)
		{
		for (y=0; y<n; y++)
			scanf ("%s",c[k][y]);
		for (y=0; y<n; y++)
			for (x=0; x<n; x++)
				if ((x+y)%2!=(c[k][y][x]-'0'))
					dis1[k]++;
		}
	for (k=1; k<=4; k++)
		dis2[k] = n*n-dis1[k];
	
	check(1,2);
	check(1,3);
	check(1,4);
	check(2,3);
	check(2,4);
	check(3,4);
	printf ("%d\n",out);
	return 0;
	}