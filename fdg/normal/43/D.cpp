#include <cstdio>
#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int n,m;

vector < vector <int> > g,tmp;

void build1(int n,int m)
{
	g.resize(n,vector <int> (m,0));
	if (m&1)
	{
		g[0][0]=3;
		for(int t=0;t<(m-3)/2;t++)
		{
			for(int i=1;i<n-1;i++)
			{
				g[i][2*t]=3;
				g[i][2*t+1]=1;
			}
			g[n-1][2*t]=2; g[n-1][2*t+1]=1; g[1][2*t+1]=2;
		}
		for(int i=1;i<n-1;i++)
			g[i][m-3]=3;
		g[n-1][m-3]=2;
		for(int i=1;i<n;i++)
		{
			if ((n-1-i)&1)
			{
				g[i][m-2]=1;
				g[i][m-1]=4;
			}
			else
			{
				g[i][m-2]=2;
				g[i][m-1]=1;
			}
		}
		for(int i=1;i<m;i++)
			g[0][i]=4;
	}
	else
	{
		g[0][0]=3;
		for(int t=0;t<m/2;t++)
		{
			for(int i=1;i<n-1;i++)
			{
				g[i][2*t]=3;
				g[i][2*t+1]=1;
			}
			g[n-1][2*t]=2; g[n-1][2*t+1]=1; g[1][2*t+1]=2;
		}
		g[1][m-1]=1;
		for(int i=1;i<m;i++)
			g[0][i]=4;
	}
}

vector <int> x,y;

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	cin >> n >> m;
	if (n==1)
	{
		if (m!=2)
		{
			printf("1\n1 %d 1 1\n",m);
		}
		else printf("0\n");
		for(int i=1;i<=m;i++)
			cout << 1 << " " << i << endl;
		cout << "1 1\n";
		return 0;
	}
	if (m==1)
	{
		if (n!=2) printf("1\n%d 1 1 1\n",n);
		else printf("0\n");
		for(int i=1;i<=n;i++)
			cout << i << " " << 1 << endl;
		cout << "1 1\n";
		return 0;
	}
	if (m%2==0)
	{
		build1(n,m);
		x.clear(); y.clear();
		int curx=0,cury=0;
		if (g[curx][cury]==1) curx--;
		else if (g[curx][cury]==2) cury++;
		else if (g[curx][cury]==3) curx++;
		else if (g[curx][cury]==4) cury--;
		while(curx!=0||cury!=0)
		{
			x.push_back(curx);
			y.push_back(cury);
			if (g[curx][cury]==1) curx--;
			else if (g[curx][cury]==2) cury++;
			else if (g[curx][cury]==3) curx++;
			else if (g[curx][cury]==4) cury--;
		}
		printf("0\n1 1\n");
		for(int i=0;i<x.size();i++)
		{
			printf("%d %d\n",x[i]+1,y[i]+1);
		}
		printf("1 1\n");
		return 0;
	}
	if (n%2==0)
	{
		swap(n,m);
		build1(n,m);
		x.clear(); y.clear();
		int curx=0,cury=0;
		if (g[curx][cury]==1) curx--;
		else if (g[curx][cury]==2) cury++;
		else if (g[curx][cury]==3) curx++;
		else if (g[curx][cury]==4) cury--;
		while(curx!=0||cury!=0)
		{
			x.push_back(curx);
			y.push_back(cury);
			if (g[curx][cury]==1) curx--;
			else if (g[curx][cury]==2) cury++;
			else if (g[curx][cury]==3) curx++;
			else if (g[curx][cury]==4) cury--;
		}
		printf("0\n1 1\n");
		for(int i=0;i<x.size();i++)
		{
			printf("%d %d\n",y[i]+1,x[i]+1);
		}
		printf("1 1\n");
		return 0;
	}
	printf("1\n%d %d 1 1\n",n,m);
	for(int i=1;i<=n;i++)
	{
		if (i&1)
		{
			for(int j=1;j<=m;j++)
				cout << i << " " << j << endl;
		}
		else
		{
			for(int j=m;j>=1;j--)
				cout << i << " " << j << endl;
		}
	}
	printf("1 1\n");
	return 0;
}