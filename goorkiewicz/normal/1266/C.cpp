#include <bits/stdc++.h>
using namespace std;

int my, mx, y, x;

int main ()
	{
	scanf("%d%d", &my, &mx);
	
	if (my==1 && mx==1)
		return printf ("0\n"), 0;
	
	if (mx==1)
		{
		for (y=2; y<=my+1; y++)
			printf("%d\n", y);
		printf ("\n");
		return 0;
		}
	
	if (my==1)
		{
		for (x=2; x<=mx+1; x++)
			printf("%d ", x);
		printf ("\n");
		return 0;
		}

	for (y=1; y<=my; y++)
		{
		for (x=1; x<=mx; x++)
			printf("%d ", y*(my+x));
		printf("\n");
		}
	
	return 0;
	}