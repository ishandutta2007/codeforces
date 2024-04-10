#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#define For(i,j,k)	for(register ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(register ll i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define pb push_back
using namespace std;
inline ll read()
{
	ll t=0,dp=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	dp=-1;c=getchar();}
	while(c>='0'&&c<='9')	t=(t*10+c-48),c=getchar();
	return t*dp;
}
ll mo=1000000007;
ll s[1005][1005],tong[1005],v[1005][1005],n,m,father[1005];
char ts[1005][1005];
inline ll getfather(ll x){
	return father[x]==x?x:father[x]=getfather(father[x]);
}

int main()
{
	m=read(); n=read();
	For(i,1,m)father[i]=i;
	For(i,1,n)
		scanf("%s",ts[i]+1);
	For(i,1,m)
		For(j,i+1,m)
		{
			ll flag=0;
			For(k,1,n){
			if(ts[k][i]!=ts[k][j])
			{
				flag=1; 
				break;
			}
		}
		if(!flag)father[i]=j;
	}
	for(ll i=1;i<=m;i++)tong[getfather(i)]++;
	ll ans=1;
	s[1][1]=1;
	For(i,2,1000)for(ll j=1;j<=i;j++)s[i][j]=(s[i-1][j-1]+(ll)s[i-1][j]*j)%mo;
	For(i,1,1000)for(ll j=1;j<=i;j++)s[i][0]=(s[i][0]+s[i][j])%mo; s[0][0]=1;
	For(i,1,m){ans=(ll)ans*s[tong[i]][0]%mo; }
	cout<<ans<<endl;
	return 0;
}