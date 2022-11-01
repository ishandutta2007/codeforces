#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e17
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	f=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-'0',c=getchar();
	return t*f;
}
inline void write(int x){if(x>=10)	write(x/10);putchar(x%10+'0');}
inline void writeln(int x){write(x);puts("");}
inline void write_p(int x){write(x);putchar(' ');}
const int N=1100055;
struct node{ll tag,ms;int mi;}	tr[4*N];
int a[N],n,m;
struct que{ll v;int num,ans;}	q[N];
inline bool cmp(que x,que y){return x.v>y.v;}
inline bool cmp1(que x,que y){return x.num<y.num;}
ll s[N],MI;
inline void Push(int x)
{
	if(tr[x].tag!=0)
	{
		tr[x<<1].tag+=tr[x].tag;tr[x<<1|1].tag+=tr[x].tag;
		tr[x<<1].ms-=tr[x].tag;tr[x<<1|1].ms-=tr[x].tag;
		tr[x].tag=0;
	}
}
inline void Up(int x)
{
	tr[x].mi=min(tr[x<<1].mi,tr[x<<1|1].mi);
	tr[x].ms=min(tr[x<<1].ms,tr[x<<1|1].ms);
}
inline void Build(int x,int l,int r)
{
	if(l==r)	{tr[x].ms=s[l],tr[x].mi=a[l];return;}
	int mid=l+r>>1;
	Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
	Up(x);
}
inline void Upd_mi(int x,int l,int r,int qx)
{
	if(l==r)	{tr[x].mi=0;return;}
	Push(x);
	int mid=l+r>>1;
	if(qx<=mid)	Upd_mi(x<<1,l,mid,qx);else	Upd_mi(x<<1|1,mid+1,r,qx);
	Up(x);
}
inline void Upd_ms(int x,int l,int r,int ql,int qr,ll qv)
{
	if(ql<=l&&r<=qr)
	{
		tr[x].ms-=qv;tr[x].tag+=qv;
		return;
	}
	Push(x);
	int mid=l+r>>1;
	if(ql<=mid)	Upd_ms(x<<1,l,mid,ql,qr,qv);
	if(qr>mid)	Upd_ms(x<<1|1,mid+1,r,ql,qr,qv);
	Up(x);
}
inline int Get_mi(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)	return tr[x].mi;
	Push(x);
	int mid=l+r>>1,tmp=1e9;
	if(ql<=mid)	tmp=min(tmp,Get_mi(x<<1,l,mid,ql,qr));
	if(qr>mid)	tmp=min(tmp,Get_mi(x<<1|1,mid+1,r,ql,qr));
	Up(x);
	return tmp;
}
inline ll Get_ms(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)	return tr[x].ms;
	Push(x);
	int mid=l+r>>1;ll tmp=inf;
	if(ql<=mid)	tmp=min(tmp,Get_ms(x<<1,l,mid,ql,qr));
	if(qr>mid)	tmp=min(tmp,Get_ms(x<<1|1,mid+1,r,ql,qr));
	Up(x);
	return tmp;
}
inline int Findit(int x,int l,int r,int qr,int qv)
{
	if(l==r)	return l;
	Push(x);
	int mid=l+r>>1,tmp=0;
	if(mid>=qr)	tmp=Findit(x<<1,l,mid,qr,qv);
	else
		if(tr[x<<1].mi==qv)	tmp=Findit(x<<1,l,mid,qr,qv);
		else	tmp=Findit(x<<1|1,mid+1,r,qr,qv);
	Up(x);
	return tmp;
}
inline int Find(int x,int l,int r,ll qms,int qmi)
{
	if(l==r)	return l;
	Push(x);
	int mid=l+r>>1,tmp=1;
	ll tms=min(qms,tr[x<<1].ms);int tmi=min(qmi,tr[x<<1].mi);
	if(MI-tmi>=tms)	tmp=Find(x<<1,l,mid,qms,qmi);
	else	tmp=Find(x<<1|1,mid+1,r,min(qms,tr[x<<1].ms),min(qmi,tr[x<<1].mi));
	Up(x);
	return tmp;
}
int main()
{
	// freopen("angry.in","r",stdin);freopen("angry.out","w",stdout);
	n=read();m=read();
	For(i,1,n)	a[i]=read();
	For(i,1,n)	s[i]=s[i-1]+a[i];
	Build(1,1,n);
	For(i,1,m)	q[i].v=read(),q[i].num=i;
	sort(q+1,q+m+1,cmp);
	int tep=1;
	MI=Get_ms(1,1,n,1,n);
	while(tep<=m&&q[tep].v+MI>=0)	q[tep++].ans=0;
	For(T,1,n)
	{
		if(tep>m)	break;
		int fac=Find(1,1,n,inf,1e9);
		fac=Findit(1,1,n,fac,Get_mi(1,1,n,1,fac));
		Upd_mi(1,1,n,fac);Upd_ms(1,1,n,fac,n,a[fac]);
		MI=Get_ms(1,1,n,1,n);
		while(tep<=m&&q[tep].v+MI>=0)	q[tep++].ans=T;
	}
	sort(q+1,q+m+1,cmp1);
	For(i,1,m)	writeln(q[i].ans);
}