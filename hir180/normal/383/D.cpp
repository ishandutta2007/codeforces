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
#define geta 10000
#define INF 2000000000
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
int dp[20005][2]={};
int main()
{
	srand((unsigned int)time(NULL));
	int n;
	scanf("%d",&n);
	int cur=0,nex=1;
	//DP
	int ret=0;
	for(int i=0;i<n;i++)
	{
		int x; scanf("%d",&x);
		for(int j=0;j<20005;j++) dp[j][nex]=0;
		for(int j=0;j<20005;j++)
		{
			if(dp[j][cur])
			{
				dp[j+x][nex]=(dp[j+x][nex]+dp[j][cur])%1000000007;
				dp[j-x][nex]=(dp[j-x][nex]+dp[j][cur])%1000000007;
			}
		}
		dp[geta+x][nex]++;
		dp[geta-x][nex]++;
		swap(cur,nex);
		ret=(ret+dp[geta][cur])%1000000007;
	}
	printf("%d\n",ret);
}