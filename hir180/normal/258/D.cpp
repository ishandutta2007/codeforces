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
double dp[1005][1005];
int main()
{
	int n,q;
	vector<int>num;
	cin >> n >> q;
	for(int i=0;i<n;i++)
	{
		int x; cin >> x;
		num.pb(x);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(num[i]>num[j]) dp[i][j]=1.0;
		}
	}
	for(int i=0;i<q;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a--; b--;
		for(int j=0;j<n;j++)
		{
			dp[j][a]=dp[j][b]=0.5*(dp[j][a]+dp[j][b]);
			dp[a][j]=1-dp[j][a]; dp[b][j]=1-dp[j][b];
		}
		dp[a][b]=dp[b][a]=0.5;
	}
	double ret=0.0;
	for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) ret+=dp[i][j];
	printf("%.20f\n",ret);
}