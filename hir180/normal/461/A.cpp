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
int main()
{
	int n;
	vector<ll>vec;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		ll x;
		cin >> x;
		vec.pb(x);
	}
	sort(vec.begin(),vec.end());
	if(n == 1)
	{
		cout << vec[0] << endl;
	}
	else if(n == 2)
	{
		cout << (vec[0]+vec[1])*2 << endl;
	}
	else
	{
		ll res = 0;
		for(int i=0;i<n-2;i++)
		{
			res += vec[i]*(i+2);
		}
		res += (vec[n-2]+vec[n-1])*1LL*(n);
		cout << res << endl;
	}
}