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
double binpow(double x,int n)
{
	double res=1;
	while(n>0)
	{
		if(n&1) res=res*x;
		x=x*x;
		n>>=1;
	}
	return res;
}
int main()
{
	int m,n;
	cin >> m >> n;
	double dp[100005];
	dp[1] = 1;
	for(int i=2;i<=m;i++)
	{
		double t = binpow((double)(i-1)/(double)(i),n);
		dp[i] = (double)i+t*(dp[i-1]-i);
	}
	printf("%.12f\n",dp[m]);
}