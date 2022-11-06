#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1010
#define M 500010
using namespace std;
struct node{
	int x,y,w,id;
	bool operator <(const node a)const{return w>a.w;}
}r[M];
int f[N*2];
int find(int x){return x==f[x]?f[x]:(f[x]=find(f[x]));}
int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&r[i].x,&r[i].y,&r[i].w),r[i].id=i;
	sort(r+1,r+m+1);
	while(q --> 0)
	{
		int lf,rf,w=-1;
		scanf("%d%d",&lf,&rf);
		for(int i=1;i<=n*2;i++) f[i]=i;
		for(int i=1;i<=m;i++)
		if(r[i].id>=lf && r[i].id<=rf)
		{
			int hx=find(r[i].x),hy=find(r[i].y),ix=find(r[i].x+n),iy=find(r[i].y+n);
			if(hx==hy || ix==iy) {w=r[i].w;break;}
			f[hx]=iy,f[hy]=ix;
		}
		printf("%d\n",w);
	}
	return 0;
}