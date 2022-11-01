#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#define For(i,j,k)	for(register ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(register ll i=k;i>=j;--i)
#define int long long
#define mk make_pair
#define pb push_back
using namespace std;
inline long long read()
{
	long long t=0,dp=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	dp=-1;c=getchar();}
	while(c>='0'&&c<='9')	t=(t*10+c-48),c=getchar();
	return t*dp;
}
int n,x,y,tx,ty,mo=1e9+7,dp[2000][2000],xxx,ans,sum;
int ksm(int x,int y){
	int ans=1;
	for(;y;y/=2){if (y&1)(ans*=x)%=mo;(x*=x)%=mo;}
	return ans;
}
signed main(){
	n=read();x=read();y=read();
	tx=ksm(x+y,mo-2)*x%mo;
	ty=ksm(x+y,mo-2)*y%mo;
	dp[1][0]=ksm(x+y,n*2);
	for (int i=1;i<=n;i++)
		for (int j=0;j<n;j++)
			if (dp[i][j])
			{
				(dp[i+1][j]+=dp[i][j]*tx)%=mo;
				if (j+i>=n)(ans+=dp[i][j]*ty%mo*(j+i)%mo)%=mo;
					else (dp[i][j+i]+=dp[i][j]*ty)%=mo;
			}
	for (int i=0;i<n;i++)
	{
		xxx=(x+(n+i+1)*y)%mo;
		xxx=xxx*ksm(y,mo-2)%mo;
		(ans+=dp[n+1][i]*xxx)%=mo;
	}(ans*=ksm(dp[1][0],mo-2))%=mo;
	cout<<ans<<endl;
}