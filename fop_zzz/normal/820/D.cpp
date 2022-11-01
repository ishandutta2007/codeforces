#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <cstring>
#include <ctime>
#include <vector>
#define inf 1e9
#define ll long long
#define For(i,j,k) for(ll i=j;i<=k;i++)
#define Dow(i,j,k) for(ll i=k;i>=j;i--)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");}
ll n,a[2000001],del[2000001],ans;
int main()
{
	n=read();
	For(i,1,n)	a[i]=read();
	For(i,1,n)
	{
		ans+=abs(a[i]-i);
		ll now=a[i];
		if(a[i]>=i)
		{
			del[0]--;
			del[now-i+1]++;del[now-i+1]++;del[n-i+1]--;
			ll bh=abs(n-a[i])-abs(1-a[i]);
			del[n-i+1]-=bh;del[n-i+2]+=bh-1;
		}
		else
		{
			del[0]++;
			del[n-i+1]--;del[now-i+1+n]++;del[now-i+1+n]++;
			ll bh=abs(n-a[i])-abs(1-a[i]);
			del[n-i+1]-=bh;del[n-i+2]+=bh-1;
		}
	}
	ll tans=ans,ans2=0;
	For(i,1,n)	del[i]+=del[i-1];
	For(i,1,n-1)
	{
		tans+=del[i];
		if(tans<ans)	ans=tans,ans2=i;
	}
	write(ans);putchar(' ');writeln(ans2);
}