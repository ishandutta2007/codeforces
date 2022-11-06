#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 2510
using namespace std;
int num[N][N];
struct node{
	int x,y;
	bool operator <(const node a)const{return num[x][y]<num[a.x][a.y];}
	bool operator ==(const node a)const{return num[x][y]==num[a.x][a.y];}
}p[N*N];
int fa[N];
int find(int x){return x==fa[x]?fa[x]:(fa[x]=find(fa[x]));}
int main()
{
	int n,tot=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) scanf("%d",&num[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			if(i==j){if(num[i][j]){puts("NOT MAGIC");return 0;}}
			else if(num[i][j]!=num[j][i]){puts("NOT MAGIC");return 0;}
			else p[++tot]=(node){i,j};
		}
	sort(p+1,p+tot+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	int l=1,r=1;
	for(;l<=tot;l=r)
	{
		for(;p[l]==p[r] && r<=tot;r++);
		for(int i=l;i<r;i++)
		if(find(p[i].x)==find(p[i].y)){puts("NOT MAGIC");return 0;}
		for(int i=l;i<r;i++) fa[find(p[i].x)]=find(p[i].y);
	}
	puts("MAGIC");
	return 0;
}