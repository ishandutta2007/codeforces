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
#define mod 1000000007
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
ll dp[1000005],gen[1000005];
ll dp2[1000005];
int rui[1000005];
int rui2[1000005];
int rui3[1000005];
ll two[1000005];
int main()
{
	int n,k; string s;
	cin >> n >> k >> s;
	reverse(s.begin(),s.end()); s.pb('#');
	reverse(s.begin(),s.end());
	for(int i=1;i<=n;i++) rui[i]=rui[i-1]+(s[i]=='W');
	for(int i=1;i<=n;i++) rui2[i]=rui2[i-1]+(s[i]=='B');
	for(int i=1;i<=n;i++) rui3[i]=rui3[i-1]+(s[i]=='X');
	dp[0]=1LL;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='X') dp[i]=dp[i-1]*2LL;
		else dp[i]=dp[i-1];
		dp[i]%=mod;
		if(i<k) continue;
		if(rui[i]-rui[i-k]==0 && s[i-k]!='B')
		{
			dp[i]-=dp[max(0,i-k-1)]; gen[i]=dp[max(0,i-k-1)];
			dp[i]=(dp[i]+mod)%mod;
		}
	}
	dp2[n+1]=1LL;
	for(int i=n;i>=1;i--)
	{
		if(s[i]=='X') dp2[i]=dp2[i+1]*2LL;
		else dp2[i]=dp2[i+1];
		dp2[i]%=mod;
		if(i>n-k+1) continue;
		if(rui2[i+k-1]-rui2[i-1]==0 && s[i+k]!='W')
		{
			dp2[i]-=dp2[min(n+1,i+k+1)];
			dp2[i]=(dp2[i]+mod)%mod;
		}
	}
	two[0]=1;
	for(int i=1;i<=1000000;i++) two[i]=(two[i-1]*2LL)%mod;
	long long ret=0LL;
	long long prev=0,prev2=0;
	for(int i=1;i<=n;i++)
	{
		long long cal=gen[i];
		int vac=rui3[n]-rui3[i];
		long long x=(two[vac]-dp2[i+1]+mod)%mod;
		ret=(ret+(cal*x)%mod)%mod;
	}
	cout << ret << endl;
}