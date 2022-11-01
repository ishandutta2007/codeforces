#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
using namespace std;
typedef long long ll;
const int N=2E5+10;
ll read()
{
	ll a=0;
	char b=1,c;
	do if((c=getchar())==45)b=-1;while(c<48||c>57);
	do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
	return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
char a[N];
int val[N<<2],l[N<<2],r[N<<2],laz[N<<2];
int u[N],v[N];
void rt(int i)
{
	val[i]=val[ls]+val[rs];
}
void dt(int i,int x)
{
	val[i]=(r[i]-l[i]+1)*x;
	laz[i]=x;
}
void build(int i,int L,int R)
{
	l[i]=L;
	r[i]=R;
	laz[i]=0;
	if(L==R)
	{
		char c=0;
		while(c!='0'&&c!='1')c=getchar();
		val[i]=c=='1'?1:-1;
		return;
	}
	int M=L+R>>1;
	build(ls,L,M);
	build(rs,M+1,R);
	rt(i);
}
int srh(int i,int L,int R)
{
	if(l[i]>R||r[i]<L)return 0;
	if(l[i]>=L&&r[i]<=R)return val[i];
	if(laz[i])
	{
		dt(ls,laz[i]);
		dt(rs,laz[i]);
		laz[i]=0;
	}
	return srh(ls,L,R)+srh(rs,L,R);
}
void cha(int i,int L,int R,int x)
{
	if(l[i]>R||r[i]<L)return;
	if(l[i]>=L&&r[i]<=R)
	{
		dt(i,x);
		return;
	} 
	if(laz[i])
	{
		dt(ls,laz[i]);
		dt(rs,laz[i]);
		laz[i]=0;
	}
	cha(ls,L,R,x);
	cha(rs,L,R,x);
	rt(i);
}
bool check()
{
	int n=read(),m=read();
	scanf("%s",a+1);
	build(1,1,n);
	for(int i=m;i>=1;--i)
	{
		u[i]=read();
		v[i]=read();
	}
	for(int i=1;i<=m;++i)
	{
		int t=srh(1,u[i],v[i]);
		if(!t)return 0;
		cha(1,u[i],v[i],t>0?1:-1);
	}
	for(int i=1;i<=n;++i)
	{
		int t=a[i]=='1'?1:-1;
		if(t!=srh(1,i,i))return 0;
	}
	return 1;
}
int main()
{
	for(int x=read();x--;)
	{
		puts(check()?"YES":"NO");
	}
}