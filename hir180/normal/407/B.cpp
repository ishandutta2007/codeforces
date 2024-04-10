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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
ll dp[1005];
int p[1005];
int main()
{
	srand((unsigned int)time(NULL));
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> p[i];
	dp[1]=2;
	for(int i=2;i<=n;i++)
	{
		dp[i] = ( (dp[i-1]*2+2-dp[p[i]-1])%mod + mod)%mod;
	}
	cout << dp[n] << endl;
}