#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double dist(double x,double y,double xx,double yy)
{
	return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}

int main()
{
	int n,m,xa,xb,l[100100],ya[100100],yb[100100];
	cin >> n >> m >> xa >> xb;
	for (int i=0;i<n;i++) cin >> ya[i];
	for (int i=0;i<m;i++) cin >> yb[i];
	for (int i=0;i<m;i++) cin >> l[i];
	
	double ans=1e18;
	int ra,rb;
	for (int i=0,j=0;i<m;i++)
	{
		while (j+1<n && 1LL*ya[j+1]*xb<=1LL*yb[i]*xa) j++;
		
		double u=dist(xa,ya[j],xb,yb[i])+dist(xa,ya[j],0,0)+l[i];
		if (u<ans) ans=u, ra=j, rb=i;
		if (j+1==n) continue;
		
		u=dist(xa,ya[j+1],xb,yb[i])+dist(xa,ya[j+1],0,0)+l[i];
		if (u<ans) ans=u, ra=j+1, rb=i;
	}
	
	cout << ra+1 << ' ' << rb+1 << endl;
}