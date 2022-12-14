#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define MAXN 200000
#define INF 2000000000
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
ll n,m;
ll s,t;
ll rr[MAXN+5],c[MAXN+5];
ll d[MAXN+5];

bool cmp(int x,int y)
{
	return x<y;
}

bool check(ll x)
{
    ll time=0;
    for(int j=1;j<=m;j++)
	{
	    if(x<d[j]-d[j-1])
	    return false;
		if(x>=2*(d[j]-d[j-1]))
		{
		   	time+=d[j]-d[j-1];
	        continue;
		}
		ll xx=(x-(d[j]-d[j-1]));
		time+=xx+(d[j]-d[j-1]-xx)*2;
		//printf("+=%d",x+(d[j]-d[j-1])*2);
	}		
	if(time<=t)
	  return true;
	else
	  return false;

}

int main()
{
	n=read();m=read();s=read();t=read();
   	for(int i=1;i<=n;i++)
   	   rr[i]=read(),c[i]=read();
   	for(int i=1;i<=m;i++)
   	   d[i]=read();
   	sort(d+1,d+m+1,cmp);
   	d[++m]=s;
   	ll minn=INF;
   	ll mindis=INF;
   	ll l=0,r=1000000000,mid;
   	
   	while(l<=r)
    {
	    mid=(l+r)/2;
		if(check(mid))
		   mindis=mid,r=mid-1;
		else
		   l=mid+1;	
	}
	for(int i=1;i<=n;i++)
	    if(c[i]>=mindis)
	       minn=min(minn,rr[i]);
	if(minn>=INF)
	   printf("-1");
	else
	   printf("%d",minn);
   	return 0;
}