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
int main()
{
	ll a,b; cin >> a >> b;
	ll res = 0;
	for(int i=1;i<b;i++)
	{
		ll x = a*(a+1)/ 2;
		x %= mod;
		x = x * b % mod;
		x = x * i % mod;
		x = (x + 1LL*i * a)%mod;
		res = (res+x)%mod;
	}
	cout << res << endl;
}