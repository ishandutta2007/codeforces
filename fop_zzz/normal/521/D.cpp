#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstring>
#include<set>
#define eps 1e-5
#define inf 1e9
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define maxn 1000000
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
int n,k,m,a[500001],top,tot,L[500001],R[500001],kind[500001];
struct node{int num,v,to;} q[500001],c[500001];
inline bool cmp(node x,node y){return x.to<y.to;}
inline bool cmp1(node x,node y){return x.v>y.v;}
struct node1{double v;int num;} ans[500001];
inline bool cmp2(node1 x,node1 y){return x.v>y.v;}
int main()
{
	n=read();k=read();m=read();
	For(i,1,n)	a[i]=read();
	For(j,1,k)
	{
		int t,i,dlt;
		t=read();i=read();dlt=read();
		kind[j]=t;
		if(t==1)
			if(dlt>=c[i].v)	c[i].v=dlt,c[i].num=j;
		if(t==2)
			q[++top].v=dlt,q[top].num=j,q[top].to=i;
		if(t==3)
			ans[++tot].v=dlt,ans[tot].num=j;
	}
	For(i,1,n)	L[i]=inf;
	For(i,1,n)
		if(a[i]<c[i].v)	
		{
			q[++top].v=c[i].v-a[i];q[top].num=c[i].num;
			q[top].to=i;
		}
	sort(q+1,q+top+1,cmp);
	For(i,1,k)	L[q[i].to]=min(L[q[i].to],i),R[q[i].to]=max(R[q[i].to],i);
	For(i,1,n)
	{
		if(L[i]==inf)	continue;
		sort(q+L[i],q+R[i]+1,cmp1);
		ll sum=a[i];
		For(j,L[i],R[i])
			ans[++tot].v=1.0*(sum+q[j].v)/sum,sum+=q[j].v,ans[tot].num=q[j].num;
	}
	sort(ans+1,ans+tot+1,cmp2);
	int hav=min(m,tot);
	printf("%d\n",hav);
	For(i,1,hav)	
		if(kind[ans[i].num]==1)	printf("%d ",ans[i].num);
	For(i,1,hav)
		if(kind[ans[i].num]==2)	printf("%d ",ans[i].num);
	For(i,1,hav)
		if(kind[ans[i].num]==3)	printf("%d ",ans[i].num);
}