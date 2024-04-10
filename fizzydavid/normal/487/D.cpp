//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
#define input1(x) x=getval()
#define input2(x,y) x=getval(),y=getval()
#define input3(x,y,z) x=getval(),y=getval(),z=getval()
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
inline int getval()
{
	int __res=0;bool __neg=0;
	char __c;__c=getchar();
	while(__c==' '||__c=='\n')__c=getchar();
	while(__c!=' '&&__c!='\n')
	{
		if(__c=='-')__neg=1;
		else __res=__res*10+__c-'0';
		__c=getchar();
	}
	if(__neg)__res=-__res;
	return __res;
}
int n,m,q,qx[300111][11],qy[300111][11];
char g[100111][11];
inline void calc(int p,int q)
{
	for(int i=1;i<=m;++i)
	{
		if(g[q][i]=='^')qx[p][i]=q-1,qy[p][i]=i;
		else qx[p][i]=qy[p][i]=-1;
	}
	qx[p][0]=qx[p][m+1]=q;qy[p][0]=0;qy[p][m+1]=m+1;
	for(int i=1;i<=m;++i)if(g[q][i]=='<')qx[p][i]=qx[p][i-1],qy[p][i]=qy[p][i-1];
	for(int i=m;i>=1;--i)if(g[q][i]=='>')qx[p][i]=qx[p][i+1],qy[p][i]=qy[p][i+1];
}
inline void update_node(int p,int l,int r)
{
	for(int i=1;i<=m;++i)
	{
		if(qx[(p<<1)+1][i]==l+r>>1&&qy[(p<<1)+1][i]>0&&qy[(p<<1)+1][i]<=m)
		{
			qx[p][i]=qx[p<<1][qy[(p<<1)+1][i]];
			qy[p][i]=qy[p<<1][qy[(p<<1)+1][i]];
		}
		else qx[p][i]=qx[(p<<1)+1][i],qy[p][i]=qy[(p<<1)+1][i];
	}
}
void build(int p,int l,int r)
{
	if(l==r)calc(p,l);
	else
	{
		build(p<<1,l,l+r>>1);
		build((p<<1)+1,(l+r>>1)+1,r);
		update_node(p,l,r);
	}
}
inline void update(int p,int l,int r,int t)
{
	if(l==r)calc(p,l);
	else
	{
		if(t<=(l+r>>1))update(p<<1,l,l+r>>1,t);else update((p<<1)+1,(l+r>>1)+1,r,t);
		update_node(p,l,r);
	}
}
inline char my_getchar()
{
	char c;
	for(c=getchar();c==' '||c=='\n';c=getchar());
	return c;
}
inline pair<int,int> query(int p,int l,int r,int tx,int ty)
{
	if(r<=tx)return MP(qx[p][ty],qy[p][ty]);
	if(tx<=(l+r>>1))return query(p<<1,l,l+r>>1,tx,ty);
	else
	{
		pair<int,int>t=query((p<<1)+1,(l+r>>1)+1,r,tx,ty);
		if(t.FF>0&&t.SS>0&&t.SS<=m)t=MP(qx[p<<1][t.SS],qy[p<<1][t.SS]);
		return t;
	}
}
int main()
{
	input3(n,m,q);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)g[i][j]=my_getchar();
	build(1,1,n);
	char op,op2;int x,y;
	pair<int,int>t;
	for(int _=0;_<q;++_)
	{
		op=my_getchar();
		input2(x,y);
		if(op=='A')t=query(1,1,n,x,y),printf("%d %d\n",t.FF,t.SS);
		else op2=my_getchar(),g[x][y]=op2,update(1,1,n,x);
	}
	return 0;
}