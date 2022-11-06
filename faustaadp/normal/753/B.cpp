#include<bits/stdc++.h>
using namespace std;
int n,m,tt,i,j,o,oo,ooo,oooo,c[592];
bool a[100],boso;
string s;
int main()
{
	for(i=0;i<=9;i++)
	{
		printf("%d%d%d%d\n",i,i,i,i);
		fflush(stdout);
		scanf("%d %d",&n,&m);
	//	fflush(stdout);
		if(n==1||m==1)
		{
			a[i]=1;
		}
	}
	for(i=0;i<=9;i++)
	{
		if(a[i]==1)
		{
			tt++;
			c[tt]=i;
		}
	}
	printf("%d%d%d%d\n",c[1],c[2],c[3],c[4]);
	fflush(stdout);
	n=0;m=0;
	scanf("%d %d",&n,&m);
//	fflush(stdout);
	if(n==4)
	{
		boso=1;
	}
	else
	{
		for(o=1;o<=4;o++)
		{
			if(boso==1)
				break;
			for(oo=1;oo<=4;oo++)
			{
				if(boso==1)
					break;
				for(ooo=1;ooo<=4;ooo++)
				{
					if(boso==1)
						break;
					for(oooo=1;oooo<=4;oooo++)
					{
						if(boso==1)
							break;
						if(o!=oo&&o!=ooo&&o!=oooo&&oo!=ooo&&oo!=oooo&&ooo!=oooo)
						{
							printf("%d%d%d%d\n",c[o],c[oo],c[ooo],c[oooo]);
							fflush(stdout);
							scanf("%d %d",&n,&m);
			//				fflush(stdout);
							if(n==4)
								boso=1;
						}
					}
				}
			}
		}
	}
}