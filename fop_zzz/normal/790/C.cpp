#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define For(i,j,k) for(int i=j;i<=k;++i)
#define Dow(i,j,k) for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e9
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
    while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
    return t*f;
}
int n;
char s[201];
int dp[101][101][101][4],totv,totk,totn,a[200],tot[5],pos[5];
inline void upd(int &x,int y){x=x<y?x:y;}
int main()
{
	n=read();
	scanf("\n%s",s+1);
	For(i,1,n)	
	{
		if(s[i]=='V')	totv++,a[i]=1;else
		if(s[i]=='K')	totk++,a[i]=2;else
			totn++,a[i]=3;
	}
	For(i,0,totv)	For(j,0,totk)	For(k,0,totn)	
		For(t,1,3)	dp[i][j][k][t]=1e9;
	dp[0][0][0][3]=0;
	For(i,0,totv)
		For(j,0,totk)
			For(k,0,totn)
			{
				For(t,1,3)
				{
					if(dp[i][j][k][t]==1e9)	continue;
					tot[1]=i;tot[2]=j;tot[3]=k;
					pos[1]=pos[2]=pos[3]=0;
					int tmp=0;
					For(ii,1,n)
					{
						if(tot[a[ii]])	tot[a[ii]]--;
						else
						{
							tmp++;
							if(!pos[a[ii]])	pos[a[ii]]=tmp;
						}
					}
					For(to,1,3)
					{
						if(t==1&&to==2)	continue;
						int t1=i,t2=j,t3=k;
						if(to==1)	t1++;else	if(to==2)	t2++;else	t3++;
						upd(dp[t1][t2][t3][to],dp[i][j][k][t]+pos[to]-1);
					}
				}
			}
	int ans=1e9;
	upd(ans,dp[totv][totk][totn][1]);upd(ans,dp[totv][totk][totn][2]);upd(ans,dp[totv][totk][totn][3]);
	cout<<ans<<endl;
}