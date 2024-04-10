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
int n,ra[20],rb[20],r[20],R[100001],B[100001],dp[100001][130],sr,sb;
char s[5];
inline void upd(int &x,int y){x=x>y?x:y;}
int main()
{
	n=read();
	int mx=(1<<n)-1;
	For(i,1,n)
	{
		scanf("\n%s",s+1);
		if(s[1]=='R')	r[i]=1;
		ra[i]=read();rb[i]=read();
		sr+=ra[i];sb+=rb[i];
	}
	For(i,0,mx)
		For(j,1,n)
			if(i&(1<<(j-1)))
				if(r[j])	R[i]++;else	B[i]++;
	For(i,0,mx)	For(j,1,120)	dp[i][j]=-1;	
	dp[0][0]=0;
	
	For(i,0,mx)
	{
		For(j,0,120)
			if(dp[i][j]>=0)
			{
				For(t,1,n)
				{
					
					if(i&(1<<(t-1)))	continue;
					int tA=min(ra[t],R[i]);
					int tB=min(rb[t],B[i]);
					upd(dp[i|(1<<(t-1))][j+tA],dp[i][j]+tB);
				}
			}
	}
	int ans=1e9;
	For(i,0,120)
	{
		if(dp[mx][i]>=0)
		{
			int ned=max(sr-i,sb-dp[mx][i]);
			ans=min(ans,ned+n);
		}
	}
	cout<<ans<<endl;
}