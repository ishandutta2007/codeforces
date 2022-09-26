#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int T;

ll anss[30000005];
ll n,lim[15];

map<ll,ll> ans;

bool ok(ll a,int b,ll c)
{
	if (a <= 10 && b > lim[a])
		return false;
	ll ret = 1;
	while (b)
	{
		if (b & 1)
			ret *= a;
		a *= a;
		b >>= 1;
	}
	return ret <= c;
}

ll get(ll v,int k)
{
	ll ret = pow(v,1.0 / k);
	while (ret > 1 && !ok(ret,k,v))
		ret--;
	while (ok(ret + 1,k,v))
		ret++;
	return ret;
}

ll solve(ll v)
{
	if (v <= 30000000 && anss[v])
		return anss[v];
	if (v > 30000000 && ans[v])
		return ans[v];
	long long ret = v - 1;
	for (int i = 2;i <= v;i++)
	{
		ll to = get(v,i);
		if (to < 2)
			break;
		ret -= solve(to);
	}
	if (v <= 30000000)
		return anss[v] = ret;
	return ans[v] = ret;
}

int main()
{
	ios::sync_with_stdio(false);
	for (int i = 2;i <= 10;i++)
	{
		long long cur = 1;
		for (int j = 1;;j++)
		{
			cur *= i;
			if (cur > 1000000000000000000ll)
			{
				lim[i] = j - 1;
				break;
			}
		}
	}
	cin >> T;
	for (int i = 1;i <= T;i++)
	{
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}