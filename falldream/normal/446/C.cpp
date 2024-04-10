#include<iostream>
#include<cstdio>
#include<queue>
#define MN 300000 
#define mod 1000000009
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,f[MN+5],sum[MN+5],a[MN+5];
struct Tree{int l,r,x,tag,a,b;}T[MN*4+5];
void Build(int x,int l,int r)
{
	if((T[x].l=l)==(T[x].r=r)){T[x].x=a[l];return;}	
	int mid=l+r>>1;
	Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
	T[x].x=(T[x<<1].x+T[x<<1|1].x)%mod;
}
int Calc(int a,int b,int len){return (1LL*a*(sum[max(0,len-2)]+1)+1LL*b*sum[len-1])%mod;}
pair<int,int> Get(int a,int b,int len){return make_pair((Calc(a,b,len+1)-Calc(a,b,len)+mod)%mod,(Calc(a,b,len+2)-Calc(a,b,len+1)+mod)%mod);}
void Mark(int x,int l,int r)
{
//	cout<<"Mark"<<x<<" "<<l<<" "<<r<<endl;
	if(!T[x].tag) T[x].tag=1,T[x].a=T[x].b=0;
	T[x].a=(T[x].a+l)%mod;T[x].b=(T[x].b+r)%mod;
	T[x].x=(T[x].x+Calc(l,r,T[x].r-T[x].l+1))%mod;
}
void pushdown(int x)
{
	Mark(x<<1,T[x].a,T[x].b);
	pair<int,int> p=Get(T[x].a,T[x].b,T[x<<1].r-T[x<<1].l+1);
	Mark(x<<1|1,p.first,p.second);
	T[x].tag=0;
}
void Modify(int x,int l,int r,int lt)
{
//	cout<<"Modify"<<x<<" "<<l<<" "<<r<<" "<<lt<<endl;
	if(T[x].l==l&&T[x].r==r){Mark(x,f[lt],f[lt+1]);return;}	
	int mid=T[x].l+T[x].r>>1;if(T[x].tag) pushdown(x);
	if(r<=mid) Modify(x<<1,l,r,lt);
	else if(l>mid) Modify(x<<1|1,l,r,lt);
	else Modify(x<<1,l,mid,lt),Modify(x<<1|1,mid+1,r,lt+mid+1-l);
	T[x].x=(T[x<<1].x+T[x<<1|1].x)%mod;
}

int Query(int x,int l,int r)
{
	if(T[x].l==l&&T[x].r==r) return T[x].x;
	int mid=T[x].l+T[x].r>>1;if(T[x].tag) pushdown(x);	
	if(r<=mid) return Query(x<<1,l,r);
	else if(l>mid) return Query(x<<1|1,l,r);
	else return (Query(x<<1,l,mid)+Query(x<<1|1,mid+1,r))%mod; 
}

int main()
{
	n=read();m=read();f[1]=f[2]=sum[1]=1;sum[2]=2;
	for(int i=3;i<=MN;++i) f[i]=(f[i-1]+f[i-2])%mod,sum[i]=(sum[i-1]+f[i])%mod;
	for(int i=1;i<=n;++i) a[i]=read();Build(1,1,n);
	for(int i=1;i<=m;++i)
	{
		int op=read(),l=read(),r=read();
		if(op==1) Modify(1,l,r,1);
		else printf("%d\n",Query(1,l,r)); 
	}
	return 0;
}