#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#define For(i,j,k) for(ll i=j;i<=k;++i)
#define Dow(i,j,k) for(ll i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
int n,q,m,ans[500001];
struct Q{int k,l,r;}	que[500001];
int a[50001];
int main()
{
	n=read();q=read();m=read();
	For(i,1,n)	ans[i]=read();
	For(i,1,q)
		que[i].k=read(),que[i].l=read(),que[i].r=read();
	For(i,1,m)	a[i]=read();
	For(t,1,m)
	{
		Dow(i,1,q)
		{
			if(que[i].k==2)	
			{
				if(que[i].l<=a[t]&&a[t]<=que[i].r)
					a[t]=que[i].r-(a[t]-que[i].l);
			}
			else
			{
				if(que[i].l<=a[t]&&a[t]<=que[i].r)
				{
					a[t]--;
					if(a[t]==que[i].l-1)	a[t]=que[i].r;
				}
			}	
		}	
		printf("%d ",ans[a[t]]);
	}
}