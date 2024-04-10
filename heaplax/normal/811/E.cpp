#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N (1<<18)
char ch;void re(int& x)
{
	while(ch=getchar(),ch<33);x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
}
using namespace std;
int n,m,q,fa[N*10],col[N*10];
int l[N],r[N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
struct node
{
	int val;
	int L[10];
	int R[10];

}w[N];
node operator + (node a,node b)
{
	a.val+=b.val;
	for(int i=0;i<n;++i)
	{
		fa[a.L[i]]=a.L[i];
		fa[a.R[i]]=a.R[i];
		fa[b.L[i]]=b.L[i];
		fa[b.R[i]]=b.R[i];
	}
	for(int i=0;i<n;++i)
		if(col[a.R[i]]==col[b.L[i]])
		{
			int x=find(a.R[i]),y=find(b.L[i]);
			if(x!=y)
			{
				fa[y]=x;
				--a.val;
			}
		}
	for(int i=0;i<n;++i)
		a.L[i]=find(a.L[i]),
		a.R[i]=find(b.R[i]);
	return a;
}
void build(int k,int a,int b)
{
	l[k]=a,r[k]=b;
	if(a==b)
	{
		w[k].val=n;
		w[k].L[0]=w[k].R[0]=a;
		for(int i=1;i<n;++i)
		{
			if(col[i*m+a]==col[(i-1)*m+a])
			{
				--w[k].val;
				fa[i*m+a]-=m;
			}
			w[k].L[i]=w[k].R[i]=find(i*m+a);
		}
		return;
	}
	build(k<<1,a,a+b>>1);
	build(k<<1|1,(a+b>>1)+1,b);
	w[k]=w[k<<1]+w[k<<1|1];
}
node ask(int k,int a,int b)
{
	if(a<=l[k] && b>=r[k])return w[k];
	int mid=l[k]+r[k]>>1;
	if(b<=mid)return ask(k<<1,a,b);
	else if(a>mid)return ask(k<<1|1,a,b);
	else return ask(k<<1,a,b)+ask(k<<1|1,a,b);
}
int main()
{
	re(n),re(m),re(q);
	for(int i=0;i<n;++i)
		for(int j=1;j<=m;++j)
			re(col[i*m+j]),fa[i*m+j]=i*m+j;
	build(1,1,m);
	for(int x,y;q--;)
	{
		re(x),re(y);
		printf("%d\n",ask(1,x,y).val);
	}
}