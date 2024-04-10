#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

#define ll long long
#define inf 1000000000000000LL

inline ll Min(ll a,ll b) {return (a<b) ? a : b;}
inline ll Max(ll a,ll b) {return (a<b) ? b : a;}
inline ll Min(ll a,ll b,ll c) {return Min(a,Min(b,c));}

int main()
{
	int n;
	cin >> n;
	vector<ll> dp;
	dp.resize(n+1,inf);
	dp[0]=0;
	for(int i=0;i<n;i++)
	{
		ll a,b;
		cin >> a >> b;
		for(int j=n;j>0;j--)
			dp[j]=Min(dp[j],dp[Min(j+1,n)],dp[Max((j-a-1),0)]+b);
	}
	cout << dp[n] << endl;
	return 0;
}