#include<algorithm>
#include<iostream>
#include<cstring> 
#include<cstdio>
#define R register
#define MN 200000
#define MB 334
#define SIZE 600
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,N,a[MN+5],num,block[MN+5],mn[MB+5][SIZE*2+5],val[MB+5][SIZE*2+5],rt[MN+5],cnt=0;
struct disc
{
	int*s,num;
	disc(int size=SIZE<<1){s=new int[size+5];num=0;}
	void Add(int x){s[++num]=x;}
	void Build(){sort(s+1,s+num+1);num=unique(s+1,s+num+1)-s-1;}
	int Calc(int x){return upper_bound(s+1,s+num+1,x)-s-1;}
}lb[MB+5],LB(MN+5);
struct Tree{int l,r,x;}T[MN*21+5];
void Init_Mn(int x)
{
	int l=(x-1)*SIZE+1,r=min(x*SIZE,N);
	for(R int i=l;i<=r;++i) lb[x].Add(a[i]),lb[x].Add(a[i+m]);
	lb[x].Build();int tot=lb[x].num;
	for(R int j=l;j<=r;++j)
	{
		int A=lb[x].Calc(a[j]),B=lb[x].Calc(a[j+m]);
		for(R int i=A;i<=tot;++i) --val[x][i];
		for(R int i=B;i<=tot;++i) ++val[x][i];
		if(j<r) for(R int i=min(A,B);i<=tot;++i) mn[x][i]=min(mn[x][i],val[x][i]);
	}	
}
void Modify(int x,int y,int l,int r,int k,int v)
{
	T[y].x=T[x].x+v;
	if(l==r) return;int mid=l+r>>1;
	if(k<=mid) T[y].r=T[x].r,Modify(T[x].l,T[y].l=++cnt,l,mid,k,v);
	else T[y].l=T[x].l,Modify(T[x].r,T[y].r=++cnt,mid+1,r,k,v);
}
int Query(int x,int l,int r,int k)
{
	if(k<l||!x) return 0;
	if(l==r) return T[x].x;
	int mid=l+r>>1;
	if(k<=mid) return Query(T[x].l,l,mid,k);
	else return T[T[x].l].x+Query(T[x].r,mid+1,r,k);
}
int main()
{
	n=read();m=read();N=n-m+1;
	for(R int i=1;i<=n;++i)a[i]=read(),LB.Add(a[i]);
	for(R int i=1;i<=N;++i) block[i]=(i-1)/SIZE+1;
	for(R int i=1;i<=block[N];++i) Init_Mn(i);
	LB.Build();int tot=LB.num;
	for(R int i=1;i<=n;++i) Modify(rt[i-1],rt[i]=++cnt,1,tot,LB.Calc(a[i]),1);
	for(int Q=read(),ans=0;Q;--Q)
	{
		int l=read(),r=read(),x=(read()^ans)-1;
		int nx=LB.Calc(x);ans=1e9;
		int Sz=Query(rt[l+m-1],1,tot,nx)-Query(rt[l-1],1,tot,nx);
		for(int i=l;i<=r&&block[i]==block[l];++i) ans=min(ans,Sz),Sz-=(a[i]<=x),Sz+=(a[i+m]<=x);
		if(block[l]+1<block[r])
			for(int i=block[l]+1,ha;i<block[r];++i)
				ha=lb[i].Calc(x),ans=min(ans,Sz+mn[i][ha]),Sz+=val[i][ha];	
		if(block[l]!=block[r])
			for(int j=(block[r]-1)*SIZE+1;j<=r;++j) ans=min(ans,Sz),Sz-=(a[j]<=x),Sz+=(a[j+m]<=x);
		printf("%d\n",ans);
	} 
	return 0;
}