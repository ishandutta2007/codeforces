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
ll dp[100005];
ll dig[100005];
vector<int>ch[100005];
vector<int>zip[100005];
queue<P>vec[10];
string x;
int n;
long long modpow(long long x,long long n)
{
	long long res=1;
	while(n>0)
	{
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
int main()
{
	cin >> x;
//I hate this problem statement
/*
	reverse(x.begin(),x.end());
	while(x.size()>1 && x[x.size()-1] == '0') x.resize(x.size()-1);
	reverse(x.begin(),x.end());
*/
	for(int i=0;i<x.size();i++) ch[0].pb(0);
	for(int i=0;i<x.size();i++) vec[(x[i]-'0')].push(mp(0,i));
	for(int i=0;i<x.size();i++) zip[0].pb(x[i]-'0');
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		string a; cin >> a;
		int z = a[0]-'0';
		while(!vec[z].empty())
		{
			P q = vec[z].front(); vec[z].pop();
			ch[q.fi][q.sc] = i;
		}
		for(int j=3;j<a.size();j++)
		{
			ch[i].pb(0); vec[(a[j]-'0')].push(mp(i,j-3)); zip[i].pb(a[j]-'0');
		}
	}
	for(int i=n;i>=0;i--)
	{
		int m = ch[i].size();
		ll cur = 0;
		for(int j=m-1;j>=0;j--)
		{
			if(ch[i][j] == 0)
			{
				dp[i] = (dp[i]+zip[i][j]*modpow(10LL,cur))%mod;
				cur++;
				if(cur == mod-1) cur = 0;
			}
			else
			{
				dp[i] = (dp[i]+dp[ch[i][j]]*modpow(10LL,cur)%mod)%mod;
				cur += dig[ch[i][j]];
				cur %= (mod-1);
			}
		}
		dig[i] = cur;
	}
	cout << dp[0] << endl;
}