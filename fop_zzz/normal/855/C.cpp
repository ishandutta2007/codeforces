#include<cstdio>
#include<string>
#include<iostream>
#include<map>
#define For(i,j,k) for(register ll i=j;i<=k;++i)
#define Dow(i,j,k) for(register ll i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
ll dp[200001][21][4],n,m,x,y,dy,xy,k,mx,tmp[11][4];
ll ans;
ll mo=1e9+7;
ll poi[400001],nxt[400001],head[400001],cnt;

inline void add(int x,int y){poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;}
inline void dfs(int x,int fa)//0->  1->  2-> 
{
	dp[x][0][0]=xy;dp[x][1][1]=1;dp[x][0][2]=dy;        
//	cout<<x<<' '<<dp[x][0][0]<<' '<<dp[x][1][1]<<' '<<dp[x][0][2]<<endl;
	for(int i=head[x];i;i=nxt[i])
	{
	
		if(poi[i]==fa)	continue;
		dfs(poi[i],x);	
		For(j,0,mx)	tmp[j][1]=tmp[j][2]=tmp[j][0]=0;
		For(j,0,mx)
		{
			Dow(K,0,j)
			{
				tmp[j][0]+=(dp[x][j-K][0])*(dp[poi[i]][K][0]+dp[poi[i]][K][1]+dp[poi[i]][K][2])%mo;
				tmp[j][1]+=(dp[x][j-K][1])*(dp[poi[i]][K][0])%mo;
				tmp[j][2]+=(dp[x][j-K][2])*(dp[poi[i]][K][0]+dp[poi[i]][K][2])%mo;
				tmp[j][0]%=mo;tmp[j][1]%=mo;tmp[j][2]%=mo;
			}
		}	
		For(j,0,mx)
			dp[x][j][1]=tmp[j][1],dp[x][j][0]=tmp[j][0],dp[x][j][2]=tmp[j][2];
	}
}
int main()
{
	n=read();m=read();
	For(i,1,n-1)	x=read(),y=read(),add(x,y),add(y,x);
	k=read();mx=read();
	xy=k-1;dy=m-k;
	dfs(1,1);
	For(i,0,mx)
		ans+=(dp[1][i][1]+dp[1][i][2]+dp[1][i][0])%mo,ans%=mo;//cout<<dp[1][i][0]<<' '<<dp[1][i][1]<<' '<<dp[1][i][2]<<' '<<endl;
	printf("%I64d",ans);
}