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
#define INF 2000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)

int n,mod;

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
	cin >> n;
	if(n == 4)
	{
		puts("YES\n1\n3\n2\n4"); return 0;
	}
	mod = n;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i == 0)
		{
			puts("NO"); return 0;
		}
	}
	
	vector<int>res;
	for(int i=1;i<=n;i++)
	{
		if(i == 1) res.pb(1);
		else if(i == n) res.pb(n);
		else
		{
			ll x = 1LL * i * modpow((ll)(i-1),(ll)(n-2)) % n;
			res.pb(x);
		}
	}
	puts("YES");
	for(int i=0;i<n;i++) cout << res[i] << endl;
}