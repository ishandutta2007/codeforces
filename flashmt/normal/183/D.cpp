#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n,m,p[3030][303],cur[303];
double g[303][3030],ans;

void update(int i)
{
	double old=g[i][0]; 
	g[i][0]=0;
	for (int k=1;k<=n;k++)
	{
		double prob=p[k][i]*0.001,tmp=g[i][k];
		g[i][k]=g[i][k-1]*(1-prob)+old*prob;
		old=tmp;
	}
}

int main()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",p[i]+j);
	
	for (int i=1;i<=m;i++) 
	{
		for (int j=0;j<=n;j++) g[i][j]=1;
		update(i);
	}
	
	for (int tshirt=1;tshirt<=n;tshirt++)
	{
		double best=-1;
		int which;
		for (int i=1;i<=m;i++)
			if (g[i][n]>best) best=g[i][n], which=i;
		ans+=best;
		update(which);
	}
			
	printf("%.12lf\n",ans);		
}