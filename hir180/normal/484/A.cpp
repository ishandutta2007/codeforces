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
ll f(ll a,ll b)
{
	ll x,y;
	for(int i=60;i>=0;i--)
	{
		if(a <= (1LL<<i)-1 && (1LL<<i)-1 <= b) return (1LL<<i)-1;
	}
	for(int i=60;i>=0;i--)
	{
		if(a >= (1LL<<i) && b >= (1LL<<i)) return (1LL<<i)+f(a-(1LL<<i),b-(1LL<<i));
	}
}
int main()
{
	int x; cin >> x;
	for(int i=0;i<x;i++)
	{
		ll a,b;
		cin >> a >> b;
		cout << f(a,b) << endl;
	}
}