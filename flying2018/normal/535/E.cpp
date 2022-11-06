#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200010
#define db double
using namespace std;
struct node{
	int x,y,id;
	bool operator <(const node a)const{return x==a.x?y>a.y:x>a.x;}
}p[N];
db slop(node x,node y){return 1.0*(x.y-y.y)*x.x*y.x/(1.0*(x.x-y.x)*x.y*y.y);}
int q[N],qt;
int has[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y),p[i].id=i;
	sort(p+1,p+n+1);
	q[++qt]=1;
	for(int i=2;i<=n;i++)
	if(p[i].x!=p[i-1].x)
	{
		while(qt>1 && slop(p[q[qt]],p[q[qt-1]])>slop(p[i],p[q[qt]])) qt--;
		if(slop(p[i],p[q[qt]])<0) q[++qt]=i;
	}
	for(int i=1;i<=qt;i++) has[p[q[i]].id]=1;
	for(int i=2;i<=n;i++) if(p[i].x==p[i-1].x && p[i].y==p[i-1].y) has[p[i].id]=has[p[i-1].id];
	for(int i=1;i<=n;i++) if(has[i]) printf("%d ",i);
	return 0;
}