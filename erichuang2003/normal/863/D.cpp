#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int a[202020];
int op[202020],l[202020],r[202020];
int b[202020];
int main()
{
	int n,q,m;
	scanf("%d %d %d",&n,&q,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=q;i++)
		scanf("%d %d %d",&op[i],&l[i],&r[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for(int i=q;i;i--)
		for(int j=1;j<=m;j++)
			if(b[j]>=l[i]&&b[j]<=r[i])
			{
				if(op[i]==1)
				{
					if(b[j]>l[i])
						b[j]--;
					else
						b[j]=r[i];
				}
				else
					b[j]=r[i]-b[j]+l[i];
			}
	for(int i=1;i<=m;i++)
		printf("%d ",a[b[i]]);
	puts("");
	return 0;
}