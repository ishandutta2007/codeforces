#include<cstdio>
#include<iostream>
using namespace std;
const int N=500100;
typedef long long LL;
int q,num;
LL g[N][20],h[N][20],c[N];
int main()
{
	scanf("%d",&q);
	LL lastans=0;num=1;c[1]=0;
	while (q--)
	{
		LL x,y,z;scanf("%I64d%I64d%I64d",&x,&y,&z);
		y^=lastans;z^=lastans;
		if (x==1)
		{
			num++;c[num]=z;
			int u=y;
			if (c[u]<z) 
			{ for (int p=18;p>=0;p--) if (c[g[u][p]]<z&&g[u][p]) u=g[u][p];u=g[u][0];if (c[u]<z) u=0;}
			g[num][0]=u;h[num][0]=c[u];
			for (int p=1;p<=18;p++) g[num][p]=g[g[num][p-1]][p-1],h[num][p]=h[num][p-1]+h[g[num][p-1]][p-1];
		//	for (int p=0;p<=18;p++) cout<<g[num][p]<<' ';cout<<endl;
		}
		else
		{
			if (z>=c[y]) z-=c[y];else { lastans=0;cout<<"0\n";continue;}
			lastans=1;
			for (int p=18;p>=0;p--) if (h[y][p]<=z&&g[y][p]) z-=h[y][p],y=g[y][p],lastans+=1<<p;
			cout<<lastans<<endl;
		}
	}
	return 0;
}