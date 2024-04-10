#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<algorithm>
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define ll long long
#define mk make_pair
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
char s[2001];
ll t[2001],ans,dp[801][11][801],n;
ll mo=1e9+7;
inline ll Dfs(ll now,ll num,ll res,ll alr)
{
	if(now==0)	if(res)	return 0;else return 1;	
	if(!alr&&dp[now][num][res]!=-1)	return dp[now][num][res];
	ll ans=0;
	For(i,0,(alr?(s[now]-'0'):9))
		ans+=Dfs(now-1,num,max(0LL,res-(i>=num?1:0)),alr&(i==s[now]-'0')),ans%=mo;
	if(!alr)	dp[now][num][res]=ans;
	return ans;
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	t[1]=1;
	For(i,2,n)	t[i]=t[i-1]*10%mo;
	reverse(s+1,s+n+1);
	memset(dp,-1,sizeof dp);

	For(i,1,n)
		For(j,0,9)
		{
			ll tmp=Dfs(n,j,i,1);
			if(j!=9)	tmp=((tmp-Dfs(n,j+1,i,1))%mo+mo)%mo;
			ans+=tmp*t[i]%mo*j%mo;ans%=mo;
		}
	cout<<ans<<endl;
}