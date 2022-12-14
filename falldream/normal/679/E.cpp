#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,Q,a[MN+5];long long pw[15];
#define pa pair<long long,int>
struct Tree{int l,r,s;long long tag,x,val,mn;}T[MN*4+5];
long long Calc(long long x)
{
	int l=1,r=12,mid,res;
	while(l<=r)
	{
		mid=l+r>>1;
		if(pw[mid]>=x) res=mid,r=mid-1;
		else l=mid+1;
	}
	return pw[res]-x;
}

void update(int x)
{
	int L=x<<1,R=x<<1|1;
	T[x].s=(T[L].s&&T[R].s&&T[L].x==T[R].x);
	T[x].mn=min(T[L].mn,T[R].mn);
	T[x].x=T[x<<1].x;
}

void Mark(int x,long long v,int kind)
{
	if(kind==3) T[x].x+=v,T[x].mn-=v,T[x].val+=v;
	else T[x].x=v,T[x].mn=Calc(v),T[x].tag=1,T[x].val=v,T[x].s=1;
}

void pushdown(int x)
{
	Mark(x<<1,T[x].val,T[x].tag+3);
	Mark(x<<1|1,T[x].val,T[x].tag+3);
	T[x].tag=T[x].val=0;	
}

void Build(int x,int l,int r)
{
	if((T[x].l=l)==(T[x].r=r))
	{
		T[x].x=a[l];T[x].s=1;
		T[x].mn=Calc(a[l]);
		return;	
	}
	int mid=l+r>>1;
	Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
	update(x);
}

void Modify(int x,int l,int r,int v,int k)
{
//	cout<<"Modify"<<x<<" "<<l<<" "<<r<<" "<<T[x].l<<" "<<T[x].r<<endl;
	if(T[x].l==l&&T[x].r==r){Mark(x,v,k);return;}	
	int mid=T[x].l+T[x].r>>1;if(T[x].val||T[x].tag) pushdown(x);
	if(r<=mid) Modify(x<<1,l,r,v,k);
	else if(l>mid) Modify(x<<1|1,l,r,v,k);
	else Modify(x<<1,l,mid,v,k),Modify(x<<1|1,mid+1,r,v,k);
	update(x);
}

long long Query(int x,int k)
{
	if(T[x].l==T[x].r) return T[x].x;
	int mid=T[x].l+T[x].r>>1;if(T[x].val||T[x].tag) pushdown(x);
	Query(x<<1|(k>mid),k);
}

void Solve(int x)
{
	if(T[x].mn>=0) return;
	if(T[x].s) {Mark(x,T[x].x,4);return;}
	if(T[x].val||T[x].tag) pushdown(x);
	Solve(x<<1);Solve(x<<1|1);update(x);
}

int main()
{	
	n=read();Q=read();pw[0]=1;
	for(int i=1;i<=12;++i) pw[i]=pw[i-1]*42;
	for(int i=1;i<=n;++i) a[i]=read();
	Build(1,1,n);
	for(int i=1,j;i<=Q;++i)
		if((j=read())==1) printf("%lld\n",Query(1,read()));
		else 
		{
			int l=read(),r=read(),x=read();
			if(j==2) Modify(1,l,r,x,2);
			else 
				{
					do Modify(1,l,r,x,3),Solve(1);
					while(T[1].mn==0); 	
				}
		}
	return 0;
}