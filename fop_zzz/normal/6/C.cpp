#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<ctime>
#include<algorithm>
#define For(i,j,k)  for(register ll i=j;i<=k;++i)
#define Dow(i,j,k)  for(register ll i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define pb push_back
#define eps 1e-8
#define pa pair<ll,ll>
#define fir first
#define sec second
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')   {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') t=t*10+c-48,c=getchar();
    return t*f;
}
int n,a[200001],sum[200001];
int main()
{
	n=read();
	For(i,1,n)	a[i]=read();
	For(i,1,n)	sum[i]=sum[i-1]+a[i];
	For(i,1,n)
	{
		if(sum[i]>sum[n]/2)	
		{
			int ans=i-1;
			if(sum[ans] <= sum[n] - sum[ans+1])  
      			 ans++;
			cout<<ans<<' '<<n-ans;
			return 0;
		}
	}
}