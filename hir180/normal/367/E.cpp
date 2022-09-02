
//Bokann ga bokka--nn!!
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define mod 1000000007
int dp[2][350][350]={};
int main(){
	int n,m,x;
	cin >> n >> m >> x;
	if(n>m){ cout << 0 << endl; return 0;}
	dp[0][0][0]=1;
	int cur=0;
	for(int i=0;i<m;i++)
	{
			int next=1-cur;
			for(int ii=0;ii<=n;ii++)for(int j=0;j<=n;j++)dp[next][ii][j]=0;
			for(int j=0;j<=n;j++)
			{
					for(int k=0;k<=n;k++)
					{
						if(!dp[cur][j][k]) continue;
						dp[next][j+1][k]+=dp[cur][j][k];
						dp[next][j+1][k]%=mod;
						dp[next][j][k+1]+=dp[cur][j][k];
						dp[next][j][k+1]%=mod;
						if(i!=x-1)
						{
							if(k){ dp[next][j+1][k-1]+=dp[cur][j][k]; dp[next][j+1][k-1]%=mod;}
							dp[next][j][k]+=dp[cur][j][k]; dp[next][j][k]%=mod;
						}
					}
			}

			cur=1-cur;
	}
	long long ret=dp[cur][n][0]*1LL;
	for(int i=1;i<=n;i++) ret=(ret*i)%mod;
	cout << ret << endl;
}