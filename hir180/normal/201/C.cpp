//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
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
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
ll dp[100005][3][2],ret=0;
int num[100005],n;
int main()
{
	srand((unsigned int)time(NULL));
	cin >> n;
	for(int i=2;i<=n;i++)
	{
		cin >> num[i];
	}
	dp[1][0][0]=0;
	for(int i=1;i<n;i++)
	{
		int even=num[i+1]%2==0?num[i+1]:num[i+1]-1;
		int odd=num[i+1]%2==1?num[i+1]:num[i+1]-1;
		if(even) dp[i+1][0][0]=max(dp[i+1][0][0],dp[i][0][0]+even);
		dp[i+1][2][1]=max(dp[i+1][2][1],dp[i][0][0]+odd);
		if(even) dp[i+1][1][0]=max(dp[i+1][1][0],dp[i][1][0]+even);
		if(even) dp[i+1][1][0]=max(dp[i+1][1][0],dp[i][1][1]+even);
		dp[i+1][1][1]=max(dp[i+1][1][1],dp[i][1][1]+odd);
		if(even) dp[i+1][2][0]=max(dp[i+1][2][0],dp[i][2][0]+even);
		if(even) dp[i+1][2][0]=max(dp[i+1][2][0],dp[i][2][1]+even);
		dp[i+1][2][1]=max(dp[i+1][2][1],dp[i][2][1]+odd);
		ret=max(ret,dp[i+1][0][0]);
		ret=max(ret,dp[i+1][2][0]);
		ret=max(ret,dp[i+1][2][1]);
	}
	cout << ret << endl;
}