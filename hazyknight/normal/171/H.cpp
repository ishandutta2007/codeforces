#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <ctime>

using namespace std;

long long n,p;

pair<long long,long long> dfs(long long f,long long c)
{
	if (f == 1)
	{
		if (c == 1)
			return make_pair(0,0);
		if (c == 2)
			return make_pair(0,1);
		if (c == 3)
			return make_pair(1,1);
		if (c == 4)
			return make_pair(1,0);
	}
	pair<long long,long long> ret;
	if (f > 31)
	{
		ret = dfs(f - 1,c);
		return make_pair(ret.second,ret.first);
	}
	long long cnt = (1ll << (f - 1)) * (1ll << (f - 1));
	if (c <= cnt)
	{
		ret = dfs(f - 1,c);
		return make_pair(ret.second,ret.first);
	}
	c -= cnt;
	if (c <= cnt)
	{
		ret = dfs(f - 1,c);
		return make_pair(ret.first,ret.second + (1ll << (f - 1)));
	}
	c -= cnt;
	if (c <= cnt)
	{
		ret = dfs(f - 1,c);
		return make_pair(ret.first + (1ll << (f - 1)),ret.second + (1ll << (f - 1)));
	}
	c -= cnt;
	ret = dfs(f - 1,c);
	return make_pair((1ll << f) - 1 - ret.second,(1ll << (f - 1)) - 1 - ret.first);
}

int main()
{
	cin >> n >> p;
	p++;
	pair<long long,long long> ret = dfs(n,p);
	cout << ret.first << ' ' << ret.second << endl;
	return 0;
}