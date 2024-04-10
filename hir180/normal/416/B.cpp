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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int dp[50005][10];
int t[50005][10];
int main()
{
	srand((unsigned int)time(NULL));
	int p,n;
	cin >> p >> n;
	for(int i=1;i<=p;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin >> t[i][j];
		}
	}
	for(int i=1;i<=p;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j] = max(dp[i-1][j],dp[i][j-1])+t[i][j];
		}
	}
	for(int i=1;i<=p;i++)
	{
		cout << dp[i][n] << (i==p?'\n':' ');
	}
}