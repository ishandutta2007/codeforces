//Bokan ga bokka--nn!!
//Daily Lunch Speciial Tanoshii !!
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
map<pair<vector<int>,int> , ll> ma;
long long dp[(1<<18)][101];
int main()
{
	srand((unsigned int)time(NULL));
	ll n,m;
	int dig[20],id=0,ten[20],cnt[10]={};
	ten[0]=1;
	cin >> n >> m;
	for(int i=1;i<=19;i++) ten[i]=(ten[i-1]*10)%m;
	while(n)
	{
		cnt[n%10]++; dig[id++]=n%10; n/=10;
	}
	dp[0][0]=1LL;
	for(int mask=0;mask<(1<<id);mask++)	
	{
		for(int i=0;i<id;i++)
		{
			if(!mask && !dig[i]) continue;
			if(((mask>>i)&1)) continue;
			for(int rem=0;rem<m;rem++)
			{
				if(!dp[mask][rem]) continue;
				dp[mask^(1<<i)][(rem*10+dig[i])%m]+=dp[mask][rem];
			}
		}
	}
	for(int i=0;i<=9;i++) for(int j=1;j<=cnt[i];j++) dp[(1<<id)-1][0]/=j;
	cout << dp[(1<<id)-1][0] << endl;
}