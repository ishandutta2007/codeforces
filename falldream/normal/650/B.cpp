#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define MN 1000000
#define INF 200000000
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x * f;
}

int n,a,b,ans=0;ll f[MN+5],T;
char st[MN+5];

int get(ll x,int i)
{
	int l=i+1-n,r=n,mid,ans=INF;
	while(l<=r)
	{
		mid=l+r>>1;
		if(f[mid]<=x) ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}

int get2(ll x,int i)
{
	int l=n+2,r=i+n-1,mid,ans=-INF;
	while(l<=r)
	{
		mid=l+r>>1;
		if(f[mid]<=x) ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}

int main()
{
	n=read();a=read();b=read();T=read();
	scanf("%s",st+1);
	for(int i=1;st[i];i++) f[i]=f[i+n]=st[i]=='w'?b+1:1;
	for(int i=n;i;i--) f[i]+=f[i+1]+a;
	for(int i=n+2;i<=n<<1;i++) f[i]+=f[i-1]+a;
	for(int i=n+1;i<=n<<1;i++) 
	{
		if(f[i]>T) break;
		ans=max(ans,i-n);
		int L=get(T-f[i]+f[n+1]-a*(i-n-1),i);
		ans=max(ans,i-L+1);
	}
	for(int i=n;i>=2;i--)
	{
		if(f[i]>T)break;
		ans=max(ans,n+2-i);
		int R=get2(T-f[i]+f[n+1]-a*(n+1-i),i);
		ans=max(ans,R-i+1);
	}
	printf("%d\n",ans);
	return 0;
}