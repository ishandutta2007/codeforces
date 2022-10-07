#include <stdio.h>
#define maxN 5010

int spe[maxN], a[maxN];

int main()
{
	int n, m, maxi=0;
	float pos;

	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d%f",&spe[i],&pos);
		for(int j=0;j<i;j++)
			if( spe[j]<=spe[i] && a[j]>a[i] ) a[i] = a[j];
		
		a[i]++;

		if( a[i] > maxi ) maxi = a[i];
	}

	printf("%d",n-maxi);

	return 0;
}