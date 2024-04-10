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
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int n,k;
string s;
ll f[100005];
ll re[100005];
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
	cin >> n >> k;
	cin >> s;
	int sum = 0;
	for(int i=0;i<n;i++) sum += (s[i]-'0');
	f[0] = 1;
	for(int i=1;i<=n;i++) f[i] = (f[i-1]*1LL*i)%mod;
	for(int i=0;i<=n;i++) re[i] = modpow(f[i],mod-2);
	ll res = 0;
	ll t = 1;
	for(int i=0;i<=n-k-1;i++)
	{
		ll comb = f[n-2-i] * re[k-1] % mod * re[n-k-1-i] % mod;
		res = (res + comb * t % mod * (ll)(sum-(s[n-1-i]-'0')) %mod );
		res %= mod;
		comb = f[n-1-i] * re[k] % mod * re[n-k-1-i] % mod;
		res = (res + comb * t % mod * (ll)(s[n-1-i]-'0') % mod);
		res %= mod;
		t = t * 10ll % mod;
		sum -= (s[n-1-i]-'0');
	}
	cout << res << endl;
}