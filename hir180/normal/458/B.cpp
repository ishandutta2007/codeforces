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
#define pb push
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
ll x[100005];
ll y[100005];
int n,m;
int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> x[i];
	for(int i=0;i<m;i++) cin >> y[i];
	ll xx = 0,yy = 0;
	for(int i=0;i<n;i++) xx+=x[i];
	for(int i=0;i<m;i++) yy+=y[i];
	sort(x,x+n);
	sort(y,y+m);
	ll res = 1e18;
	ll sum = 0;
	for(int i=n;i>=1;i--)
	{
		sum += x[n-i];
		if(1000000000000000000LL / yy < 1LL*i) continue;
		res = min(res,sum-x[n-i]+yy*i);
	}
	sum = 0;
	for(int i=m;i>=1;i--)
	{
		sum += y[m-i];
		if(1000000000000000000LL / xx < 1LL*i) continue;
		res = min(res,sum-y[m-i]+xx*i);
	}
	cout << res << endl;
}