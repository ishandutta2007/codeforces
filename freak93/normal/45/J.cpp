#include<cstdio>
#include<algorithm>

using namespace std;

int n,x,m,a[1005][1005],i,j;

int main()
{
	scanf("%d%d",&n,&m);
	if(min(n,m)==1&&(max(n,m)==2||max(n,m)==3))
	{
		printf("-1");
		return 0;
	}
	if(n==1&&m==4)
	{
		printf("3 1 4 2\n");
		return 0;
	}
	if(n==4&&m==1)
	{
		printf("3\n1\n4\n2\n");
		return 0;
	}
    if(n==2&&m==2)
	{
		printf("-1\n");
		return 0;
	}
	if(m==2)
	{
		a[1][1]=1;a[1][2]=4;
		for(i=2;i<=n;++i)
		{
			a[i][1]=a[i-1][1]+2;
			a[i][2]=a[i-1][2]+2;
			if(a[i][2]>n*m)
				a[i][2]=2;
		}
	}
	else if(n==2)
	{
		a[1][1]=1;
		a[2][1]=4;
		for(i=2;i<=m;++i)
		{
			a[1][i]=a[1][i-1]+2;
			a[2][i]=a[2][i-1]+2;
			if(a[2][i]>n*m)
				a[2][i]=2;
		}
	}
	else
	{
		x=1;
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=m;++j)
				if(x>n*m)
					break;
				else
					a[i][j]=x,x+=2;
			if(j<=m)
				break;
		}
		x=2;
		for(;j<=m;++j)
			a[i][j]=x,x+=2;
		for(++i;i<=n;++i)
			for(j=1;j<=m;++j)
				a[i][j]=x,x+=2;
	}
	for(i=1;i<=n;++i,printf("\n"))
		for(j=1;j<=m;++j)
			printf("%d ",a[i][j]);
}