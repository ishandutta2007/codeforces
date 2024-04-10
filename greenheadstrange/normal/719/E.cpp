#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define maxn 100005
#define pos 10000
using namespace std;

struct matrix
{
       long long hs,ls;
       long long a[3][3];// bg fr 1
};
int n,m;
long long mode=1000000007;
matrix multi(matrix a, matrix b)
{
    matrix c;
    c.hs=a.hs;c.ls=b.ls;
    for(int i=1;i<=2;i++)
    	for(int j=1;j<=2;j++) c.a[i][j]=0;
    for(int i=1;i<=a.hs;i++)
        for(int j=1;j<=b.ls;j++)
            for(int k=1;k<=a.ls;k++)
            {
                c.a[i][j]+=a.a[i][k]*b.a[k][j];
                c.a[i][j]%=mode;
            }
    return c;
}

matrix add(matrix a,matrix b)
{
	matrix c;
    c.hs=a.hs;c.ls=b.ls;
  	for(int i=1;i<=2;i++)
    	for(int j=1;j<=2;j++) c.a[i][j]=0;
    for(int i=1;i<=a.hs;i++)
        for(int j=1;j<=a.ls;j++)
        {
			c.a[i][j]=a.a[i][j]+b.a[i][j];
			c.a[i][j]%=mode;
		}
				
    return c;
}
struct ST
{
	long long l,r,lazy;
	matrix sum;
	ST *ch[2];
}pool[maxn*3],*root;
matrix d[maxn];
int cnt=0;

matrix lt[pos][4];
matrix power(matrix a,long long c)
{
    matrix now=lt[c % pos][0];
    for(int i=1;i<4;i++)
    {
            c/=pos;
            now=multi(now,lt[c%pos][i]);
    }
    return now;
}
void bdtree(ST *a,long long l,long long r)
{
	long long mid=(l+r)/2;
	a->l=l;a->r=r;a->lazy=0;
	if(l==r)
	{
		a->sum=d[l];
		return ;
	}
	a->ch[0]=&pool[cnt++];
	a->ch[1]=&pool[cnt++];
	bdtree(a->ch[0],l,mid),bdtree(a->ch[1],mid+1,r);
	a->sum=add(a->ch[0]->sum,a->ch[1]->sum);
}
matrix po;

void pushdown(ST *a)
{
	if(a->lazy)
	{
		if(a->ch[0])
		{
			a->ch[0]->lazy+=a->lazy;
			a->ch[0]->sum=multi(a->ch[0]->sum,power(po,a->lazy));
		}
		if(a->ch[1])
		{
			a->ch[1]->lazy+=a->lazy;
			a->ch[1]->sum=multi(a->ch[1]->sum,power(po,a->lazy));
		}
		a->lazy=0;
	}
}
void change(ST *a,int ql,int qr,int x)
{
	int l=a->l,r=a->r;
	if(ql==l && qr==r) 
	{
		a->lazy+=x;
		a->sum=multi(a->sum,power(po,x));
		return ;
	}
	pushdown(a);
	long long mid=(l+r)/2;
	if(qr<=mid) change(a->ch[0],ql,qr,x);
	else if(ql>mid) change(a->ch[1],ql,qr,x);
	else change(a->ch[0],ql,mid,x),change(a->ch[1],mid+1,qr,x);
	a->sum=add(a->ch[0]->sum,a->ch[1]->sum);
}
long long query(ST *a,long long ql,long long qr)
{
	long long l=a->l,r=a->r;
	if(ql==l && qr==r) 
		return a->sum.a[1][2];
	pushdown(a);
	long long mid=(l+r)/2;
	if(qr<=mid) return query(a->ch[0],ql,qr);
	else if(ql>mid) return query(a->ch[1],ql,qr);
	else return query(a->ch[0],ql,mid)+query(a->ch[1],mid+1,qr);
}

int main()
{
	po.hs=po.ls=2;
	po.a[1][1]=0;po.a[1][2]=1;
	po.a[2][1]=1;po.a[2][2]=1;
	scanf("%d%d",&n,&m);
	matrix bf;
	bf.hs=1;bf.ls=2;bf.a[1][1]=1;bf.a[1][2]=0;
	for(int i=0;i<4;i++)
    {
        lt[0][i].ls=lt[0][i].hs=2;
    	lt[0][i].a[1][1]=lt[0][i].a[2][2]=1;
    	lt[0][i].a[1][2]=lt[0][i].a[2][1]=0;
    }
    for(int i=1;i<pos;i++) lt[i][0]=multi(lt[i-1][0],po);
    for(int i=1;i<4;i++)
    {
            lt[1][i]=multi(lt[1][i-1],lt[pos-1][i-1]);
            for(int j=2;j<pos;j++) lt[j][i]=multi(lt[j-1][i],lt[1][i]);
    }
	for(int i=1;i<=n;i++)
	{
		int anow;
		scanf("%d",&anow);
		d[i].hs=1,d[i].ls=2;
		d[i].a[1][1]=multi(bf,power(po,anow)).a[1][1];
		d[i].a[1][2]=multi(bf,power(po,anow)).a[1][2];
	}
	root=&pool[cnt++];
	bdtree(root,1,n);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)
		{
			long long d;
			scanf("%d",&d);
			change(root,b,c,d);
		}
		else
		{
			long long ans=query(root,b,c);
			ans%=mode;
			if(ans<0 ) ans+=mode;
			printf("%I64d\n",ans);
		 }
	}
	//system("pause");
	return 0;
}