#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
const int sz = 1000;
int n, m;
int a[sz][sz], tl[sz][sz], tr[sz][sz], bl[sz][sz], br[sz][sz];
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,0,n)
	{
		rep(j,0,m)
		{
			scanf("%d",&a[i][j]);
			tl[i][j] = a[i][j];
			tr[i][j] = a[i][j];
			bl[i][j] = a[i][j];
			br[i][j] = a[i][j];
		}
	}
	rep(j,1,m)
	{
		tl[0][j]=a[0][j]+tl[0][j-1];
		bl[n-1][j]=a[n-1][j]+bl[n-1][j-1];
	}
	for(int j=m-2;j>=0;--j)
	{
		tr[0][j]=a[0][j]+tr[0][j+1];
		br[n-1][j]=a[n-1][j]+br[n-1][j+1];
	}
	rep(i,1,m)
	{
		tl[i][0]=a[i][0]+tl[i-1][0];
		tr[i][m-1]=a[i][m-1]+tr[i-1][m-1];
	}
	for(int i=n-2;i>=0;--i)
	{
		bl[i][0]=a[i][0]+bl[i+1][0];
		br[i][m-1]=a[i][m-1]+br[i+1][m-1];
	}
	rep(i,1,n)
	{
		rep(j,1,m)
			tl[i][j]+=max(tl[i-1][j],tl[i][j-1]);
		for(int j=m-2;j>=0;--j)
			tr[i][j]+=max(tr[i-1][j],tr[i][j+1]);
	}
	for(int i=n-2;i>=0;--i)
	{
		rep(j,1,m)
			bl[i][j]+=max(bl[i+1][j],bl[i][j-1]);
		for(int j=m-2;j>=0;--j)
			br[i][j]+=max(br[i+1][j],br[i][j+1]);
	}
	int best=0;
	rep(i,1,n-1)
		rep(j,1,m-1)
	{
		int v= tl[i-1][j]+tr[i][j+1]+br[i+1][j]+bl[i][j-1];
		if(v>best)
			best=v;
		v = tl[i][j-1]+tr[i-1][j]+br[i][j+1]+bl[i+1][j];
		if(v>best)
			best=v;
	}
	printf("%d\n",best);
}