//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
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
int main()
{
	int n,m;
	vector<ll>a,b;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		ll x; cin >> x;
		a.pb(x);
	}
	for(int i=1;i<=m;i++)
	{
		ll x; cin >> x;
		b.pb(x);
	}
	ll lb=-1LL;
	ll ub=1e12;
	//(lb,ub]
	while(ub-lb>1)
	{
		ll mid=(lb+ub)/2; int i,j;
		for(i=0,j=0;i<a.size()&&j<b.size();i++)
		{
			int p=j;
			while(j<b.size() && b[j]-b[p]+min(abs(b[p]-a[i]),abs(b[j]-a[i]))<=mid) j++;
		}
		if(j==b.size()) ub=mid;
		else lb=mid;
	}
	cout << ub << endl;
}