#include<iostream>
#include<cstdio>
#include<cstring>
#define N 2010
using namespace std;
int x[N],y[N],ix[N],iy[N];
struct node{
	int x1,y1,x2,y2;
}ans[N];
int tot;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]),ix[x[i]]=i;
	for(int i=1;i<=n;i++) scanf("%d",&y[i]),iy[y[i]]=i;
	for(int i=1;i<n;i++)
	if(x[i]!=i || y[i]!=i)
	{
		if(ix[i]==n && iy[i]==n)
		{
			ans[++tot]=(node){i,n,n,i};
			x[n]=x[i];
			y[n]=y[i];
			ix[x[n]]=n,iy[y[n]]=n;
		}
		else if(iy[i]==n)
		{
			ans[++tot]=(node){ix[i],i,i,n};
			y[n]=y[i];iy[y[n]]=n;
			x[ix[i]]=x[i];ix[x[ix[i]]]=ix[i];
		}
		else if(ix[i]==n)
		{
			ans[++tot]=(node){i,iy[i],n,i};
			x[n]=x[i];ix[x[n]]=n;
			y[iy[i]]=y[i];iy[y[iy[i]]]=iy[i];
		}
		else
		{
			ans[++tot]=(node){ix[i],i,i,n};
			ans[++tot]=(node){i,iy[i],n,i};
			int x0=ix[i],y0=iy[i];
			x[x0]=x[n],x[n]=x[i];
			y[y0]=y[n],y[n]=y[i];
			ix[x[x0]]=x0,iy[y[y0]]=y0;
			ix[x[n]]=n,iy[y[n]]=n;
		}
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++) printf("%d %d %d %d\n",ans[i].x1,ans[i].y1,ans[i].x2,ans[i].y2);
	return 0;
}