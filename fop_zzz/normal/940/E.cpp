#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<ctime>
#include<algorithm>
#define For(i,j,k)  for(register int i=j;i<=k;++i)
#define Dow(i,j,k)  for(register int i=k;i>=j;--i)
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
ll tr[800001],dp[800001],sum,a[200001],ans=0,n,c;
inline void Build(int x,int l,int r)
{
	if(l==r)	{tr[x]=a[l];return;}
	int mid=l+r>>1;
	Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
	tr[x]=min(tr[x<<1],tr[x<<1|1]);
}
inline ll Query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)	return tr[x];
	ll tmp=1e17;
	int mid=l+r>>1;
	if(ql<=mid)	tmp=min(tmp,Query(x<<1,l,mid,ql,qr));
	if(qr> mid)	tmp=min(tmp,Query(x<<1|1,mid+1,r,ql,qr));
	return tmp;	
}
int main()
{
	n=read();c=read();
	For(i,1,n)	a[i]=read(),sum+=a[i];
	Build(1,1,n);
	For(i,1,n)
	{
		dp[i]=dp[i-1];
		if(i>=c)
			dp[i]=max(dp[i],dp[i-c]+Query(1,1,n,i-c+1,i));
	}
	For(i,1,n)	ans=max(ans,dp[i]);
	cout<<sum-ans<<endl;
}