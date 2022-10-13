#include <iostream>
#include <cstdio>
#define rep(a,b) for (int a=0;a<b;a++)
using namespace std;

int n,a[1000100],d[1<<22];

int main()
{
	cin >> n;
	rep(i,1<<22) d[i]=-1;
	rep(i,n) scanf("%d",&a[i]), d[a[i]]=a[i];
	rep(i,1<<22) 
		if (d[i]<0)
			rep(j,22)
				if (((i>>j)&1) && d[i^(1<<j)]>=0)
					d[i]=d[i^(1<<j)];
	rep(i,n) printf("%d ",d[(1<<22)-a[i]-1]);
}