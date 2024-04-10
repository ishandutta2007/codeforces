#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100010;
struct rec {int l,r,id;};
int n,p,m,lim;
int cnt[N],id[N],a[N],b[N];
int ans[N];
rec q[N];
struct matrix
{
	int a[2][2];
};
matrix operator + (matrix a,matrix b) 
{
	matrix c;
	for (int i=0;i<2;i++)
	for (int j=0;j<2;j++)
		c.a[i][j]=(a.a[i][j]+b.a[i][j])%p;
	return c;
}
matrix operator * (matrix a,matrix b)
{
	matrix c;
	for (int i=0;i<2;i++)
	for (int j=0;j<2;j++)
		c.a[i][j]=0;
	for (int i=0;i<2;i++)
	for (int j=0;j<2;j++)
	for (int k=0;k<2;k++)
		c.a[i][k]=(c.a[i][k]+a.a[i][j]*b.a[j][k])%p;
	return c;
}
matrix t[N*4],base[N*4];
int size[N*4];
void change(int i,int l,int r,int k,int d)
{
	if (l==r)
	{
		if (d>=0) 
		{
			t[i].a[0][0]=d;t[i].a[0][1]=0;
			t[i].a[1][0]=0;t[i].a[1][1]=0;
			size[i]=1;
		}
		else 
		{
			t[i].a[0][0]=0;t[i].a[0][1]=0;
			t[i].a[1][0]=0;t[i].a[1][1]=0;
			size[i]=0;
		}
		return;
	}
	int mid=(l+r)>>1;
	if (k<=mid) change(i*2,l,mid,k,d);
	if (k> mid) change(i*2+1,mid+1,r,k,d);
	t[i]=t[i*2]+base[size[i*2]]*t[i*2+1];
	size[i]=size[i*2]+size[i*2+1];
}
void add(int i,int d)
{
	if (d==1)
	{
		
		if (cnt[b[i]]==0) change(1,1,n,b[i],a[i]);
		cnt[b[i]]++;
	}
	if (d==-1)
	{
		if (cnt[b[i]]==1) change(1,1,n,b[i],-1);
		cnt[b[i]]--;
	}
}

int cmp (int i,int j) { return a[i]<a[j];}
int cmpq(rec a,rec b) { return (a.l/lim<b.l/lim)||(a.l/lim==b.l/lim&&a.r<b.r);}
int main()
{
	scanf("%d%d",&n,&p);
	lim=sqrt(n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+1+n,cmp);
	for (int i=1,j=0;i<=n;i++)
	{
		if (a[id[i]]!=a[id[i-1]]) j++;
		b[id[i]]=j;
	}
	int l=1,r=0;
	scanf("%d",&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&q[i].l,&q[i].r);
	for (int i=1;i<=m;i++) q[i].id=i;
	sort(q+1,q+1+m,cmpq);
	
	base[0].a[0][0]=1;base[0].a[0][1]=0;
	base[0].a[1][0]=0;base[0].a[1][1]=1;
	base[1].a[0][0]=0;base[1].a[0][1]=1;
	base[1].a[1][0]=1;base[1].a[1][1]=1;
	for (int i=2;i<=n;i++) base[i]=base[i-1]*base[1];
	
	
	for (int i=1;i<=m;i++)
	{
		while (r<q[i].r) r++,add(r,1);
		while (l>q[i].l) l--,add(l,1);
		while (l<q[i].l) add(l,-1),l++;
		while (r>q[i].r) add(r,-1),r--;
		ans[q[i].id]=(t[1].a[0][0]+t[1].a[1][0])%p;
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}