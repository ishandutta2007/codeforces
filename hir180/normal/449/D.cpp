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
typedef pair<int,long long> P;
typedef pair<long long,int> Q;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int c[(1<<20)];
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
	int n; cin >> n;
	for(int i=0;i<n;i++)
	{
		int x; scanf("%d",&x);
		c[x]++;
	}
	for(int j=0;j<20;j++)
	{
		for(int i=0;i<(1<<20);i++)
		{
			if(((i>>j)&1)) continue;
			c[i] += c[i+(1<<j)];
		}
	}
	ll res = 0;
	for(int i=1;i<(1<<20);i++)
	{
		if(!c[i]) continue; //cout << i << " " << c[i] <<  endl;
		if(__builtin_popcount(i)%2 == 1)
		{
			res += (modpow(2,c[i])+mod-1)%mod;
		}
		else
		{
			res += (mod-(modpow(2,c[i])+mod-1)%mod);
		}
		res %= mod;
	}
	cout << (modpow(2,n)+mod-1-res)%mod << endl;
}