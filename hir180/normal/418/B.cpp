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
ll dp[(1<<20)+5];
struct friends
{
	int cost,maxv,mask;
	bool operator < (const friends& f) const
	{
		return maxv < f.maxv;
	}
};
int main()
{
	srand((unsigned int)time(NULL));
	fill(dp,dp+(1<<20)+5,2e18);
	dp[0]=0;
	int n,m,c;
	cin >> n >> m >> c;
	vector<friends>vec;
	for(int i=0;i<n;i++)
	{
		int cost,nes,sol;
		cin >> cost >> nes >> sol;
		int mask=0;
		for(int i=0;i<sol;i++)
		{
			int f; cin >> f;
			mask |= (1<<(f-1));
		}
		vec.pb( (friends){cost,nes,mask} );
	}
	sort(vec.begin(),vec.end());
	ll res=2e18;
	for(int i=0;i<vec.size();i++)
	{
		for(int j=0;j<1<<m;j++)
		{
			if(dp[j] == 2e18) continue;
			dp[j | vec[i].mask] = min(dp[j | vec[i].mask],dp[j]+vec[i].cost);
		}
		res = min(res,dp[(1<<m)-1]+1LL*c*vec[i].maxv);
	}
	cout << (res==2e18?-1:res) << endl;
}