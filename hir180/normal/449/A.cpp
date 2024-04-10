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
#define INF 1000000001
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int main()
{
    ll n,m,k; cin >> n >> m >> k;
    if(n+m-2 < k)
    {
    	puts("-1"); return 0;
    }
    ll res = 0;
    for(int i=0;i<=min(1000000ll,k);i++)
    {
    	ll nn = n/(i+1);
    	ll mm = m/(k+1-i);
    	res = max(res,nn*mm);
    }
    for(int i=1;i<=min(1000000ll,n);i++)
    {
    	ll nn = (ll)i;
    	ll x = n/(ll)i;
    	if(k < x-1) continue;
	ll mm = m / (ll)(k+2-x);
	res = max(res,nn*mm);
    }
    for(int i=0;i<=min(1000000ll,k);i++)
    {
    	ll nn = m/(i+1);
    	ll mm = n/(k+1-i);
    	res = max(res,nn*mm);
    }
    for(int i=1;i<=min(1000000ll,m);i++)
    {
    	ll nn = (ll)i;
    	ll x = m/(ll)i;
    	if(k < x-1) continue;
	ll mm = n / (ll)(k+2-x);
	res = max(res,nn*mm);
    }
    cout << res << endl;
}