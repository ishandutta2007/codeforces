#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct point {int x,y;};
const int N=6010;
const double pi=acos(-1);
int n;
double ans;
point a[N],b[N],tmp[N];
point now;
double c[N],g[N][20];
int xx[N],id[N];
point operator -(point a,point b) { return (point){a.x-b.x,a.y-b.y};}
double q(int l,int r)
{
	if (l>r) return -1;
	int i=xx[r-l+1];
	return max(g[l][i],g[r-(1<<i)+1][i]);
}
double dist(point a) { return sqrt(a.x*a.x+a.y*a.y);}
int cmp(int i,int j) { return c[i]<c[j];}
int main()
{
	scanf("%d",&n);
	ans=0;
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	xx[1]=0;
	for (int i=2;i<=n*2;i++) xx[i]=xx[i/2]+1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) id[j]=j,b[j]=a[j];
		swap(b[i],b[n]);now=b[n];
		for (int j=1;j<n;j++) c[j]=atan2(b[j].y-now.y,b[j].x-now.x);
		sort(id+1,id+n,cmp);
		for (int j=1;j<n;j++) tmp[j]=b[id[j]];
		for (int j=1;j<n;j++) b[j]=tmp[j];
		
		for (int j=1;j<n;j++) 
		{
			c[j]=atan2(b[j].y-now.y,b[j].x-now.x);
	//		printf("%d %d %lf\n",i,j,c[j]);
			g[j][0]=dist(b[j]-now);
			b[j+n-1]=b[j];
			c[j+n-1]=c[j]+2*pi;
			g[j+n-1][0]=g[j][0];
		}
		for (int k=0;(1<<k)<=n-1;k++)
		for (int j=1;j+(1<<(k+1))<=n*2-2;j++)
			g[j][k+1]=max(g[j][k],g[j+(1<<k)][k]);
		for (int j=1,k1=1,k2=1;j<n;j++)
		{
			while (c[k1]-c[j]<pi/3&&k1<2*n-2) k1++;
			while (c[k2]-c[j]-1e-6<pi&&k2<=2*n-2) k2++;
	//		printf("%d %d %d %d",i,j,k1,k2);
			ans=max(ans,min(g[j][0],q(k1,k2-1)));
	//		printf(" %lf\n",ans/2);
		}
		
	}
	printf("%.8lf\n",ans/2);
	return 0;
}