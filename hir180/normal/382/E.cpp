//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define mod 1000000007
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
ll dp[55][55][2]={};
ll C[105][105];
//dp[x][y][z]=xy z
int n,kk;
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d %d",&n,&kk);
	C[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(!j || j==i) C[i][j]=1LL;
			else C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
	dp[1][0][0]=1ll;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=kk;j++)
		{
			//1.........
			//
			
			//(i-1)
			dp[i][j][0]+=(1LL*(i-1)*dp[i-1][j][1])%mod;
			//(i-1)
			if(j) dp[i][j][1]+=(1LL*(i-1)*dp[i-1][j-1][0])%mod;
			
			dp[i][j][0]%=mod;
			dp[i][j][1]%=mod;
			
			
			//(i-1)C2*(i-3)C(k)
			for(int k=0;k<=i-3;k++)
			{
				ll v=(1LL*C[i-1][2]*C[i-3][k])%mod;
				for(int m1=0;m1<=j;m1++)
				{
					
						int m2=j-m1;
						//
						dp[i][j][0]+=(v*((dp[k+1][m1][1]*dp[i-2-k][m2][1])%mod))%mod;
						dp[i][j][0]%=mod;
						//
						m2--;
						if(m2<0) continue;
						dp[i][j][1]+=(v*((dp[k+1][m1][1]*dp[i-2-k][m2][0])%mod))%mod;
						dp[i][j][1]%=mod;
						dp[i][j][1]+=(v*((dp[k+1][m1][0]*dp[i-2-k][m2][0])%mod))%mod;
						dp[i][j][1]%=mod;
						dp[i][j][1]+=(v*((dp[k+1][m1][0]*dp[i-2-k][m2][1])%mod))%mod;
						dp[i][j][1]%=mod;
				}
			}
		}
	}
	printf("%lld\n",(dp[n][kk][0]+dp[n][kk][1])%mod);
}