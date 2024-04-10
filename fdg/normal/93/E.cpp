#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <set>
#pragma comment(linker, "/STACK:65777216")

#define ll long long

using namespace std;

ll n,res=0,val;
int k,nums[104];

int dp[101][500001];

ll calc(ll n,int k)
{
	if (k==-1||n==0) return n;
	if (n<=500000&&dp[k][n]!=-1) return dp[k][n];
	ll val=calc(n,k-1)-calc(n/nums[k],k-1);
	if (n<=500000) dp[k][n]=val;
	return val;
}

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	cin >> n >> k;
	for(int i=0;i<k;i++)
		cin >> nums[i];
	sort(nums,nums+k);
	memset(dp,-1,sizeof(dp));
	cout << calc(n,k-1) << endl;
	return 0;
}