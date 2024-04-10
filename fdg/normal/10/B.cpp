#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	long n,K,m;
	bool D[101][101]={0};
	long F[101][101]={0};
	scanf("%d%d",&n,&K);
	for(int i=1;i<=K;i++)
		for(int j=1;j<=K;j++)
			F[i][j]=labs((K+1)/2-i)+labs((K+1)/2-j);
	for(int r=0;r<n;r++)
	{
		scanf("%d",&m);
		int i,j,t,sum=0,kol=0,x,yl,yr,sm=-1;
		for(i=1;i<=K;i++)
		{
			sum=0; kol=0;
			for(j=1;j<=K;j++)
			{
				if (!D[i][j])
				{
					sum+=F[i][j];
					kol++;
					if (kol==m)
					{
						if (sm==-1||sum<sm)
						{
							sm=sum;
							x=i;
							yr=j;
							yl=j-m+1;
						}
						kol--;
						sum-=F[i][j-m+1];
					}
				}
				else
				{
					kol=0;
					sum=0;
				}
			}
		}
		if (sm!=-1)
		{
			for(i=yl;i<=yr;i++)
				D[x][i]=true;
			printf("%d %d %d\n",x,yl,yr);
		}
		else
			printf("-1\n");
	}
	return 0;
}