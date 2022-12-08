#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
const int SZ=100;
int a[SZ][SZ], n, m, numR[SZ], numC[SZ];
bool switched=false;
int main()
{
	scanf("%d%d",&n,&m);
	if(n>m)
		switched=true;
	rep(i,0,n)
	{
		int x;
		rep(j,0,m)
		{
			scanf("%d",&x);
			if(switched)
				a[j][i]=x;
			else
				a[i][j]=x;
		}
	}
	if(switched)
		swap(n,m);
	int moves=0;
	rep(i,0,n)
	{
		int mn=1000;
		rep(j,0,m)
			if(a[i][j]<mn)
				mn=a[i][j];
		numR[i] = mn;
		moves+=mn;
		if(mn>0)
			rep(j,0,m)
				a[i][j]-=mn;
	}
	rep(j,0,m)
	{
		int mn=1000;
		rep(i,0,n)
			if(a[i][j]<mn)
				mn=a[i][j];
		moves+=mn;
		numC[j] = mn;
		if(mn>0)
			rep(i,0,n)
				a[i][j]-=mn;
	}
	bool ok=true;
	rep(i,0,n)
	{
		rep(j,0,m)
			if(a[i][j]>0)
				ok=false;
	}
	if(ok)
	{
		printf("%d\n",moves);
		rep(i,0,n)
		{
			rep(k,0,numR[i])
				if(switched)
					printf("col %d\n",i+1);
				else
					printf("row %d\n",i+1);
		}
		rep(i,0,m)
		{
			rep(k,0,numC[i])
				if(switched)
					printf("row %d\n",i+1);
				else
					printf("col %d\n",i+1);
		}
	}
	else
		printf("-1\n");
}