//IOI2014
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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int dp[2005][2005];
int main()
{
	int n,k;
	dp[0][1]=1;
	for(int i=1;i<=2000;i++)
	{
		for(int j=1;j<=2000;j++)
		{
			if(!dp[i-1][j]) continue;
			for(int k=j;k<=2000;k+=j)
			{
				dp[i][k] = (dp[i][k]+dp[i-1][j])%mod;
			}
		}
	}
	ll res=0;
	cin >> n >> k;
	for(int i=1;i<=n;i++) res=(res+dp[k][i])%mod;
	cout << res << endl;
}