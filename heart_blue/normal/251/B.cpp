#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
vector<int> trans(vector<int>& p, vector<int>& q)
{
	vector<int> ret(p.size(), 0);
	for (int i = 0; i < ret.size(); i++)
	{
		ret[i] = p[q[i]];
	}
	return ret;
}
vector<int> rev(vector<int>& p, vector<int>& q)
{
	vector<int> ret(q.size(), 0);
	for (int i = 0; i < ret.size(); i++)
	{
		ret[q[i]] = p[i];
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	vector<int> q, key, v;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		q.push_back(x - 1);
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		key.push_back(x - 1);
		v.push_back(i - 1);
	}
	if (v == key)
	{
		puts("NO");
		return 0;
	}
	vector<int> ret = v;
	int flag1 = 0, flag2 = 0;
	int t1 = 0;
	int t2 = 0;
	for (int i = 1; i <= k; i++)
	{
		ret = trans(ret, q);
		if (ret == key)
		{
			t1 = i;
			if (i & 1) flag1 = 1;
			else flag2 = 1;
			break;
		}
	}
	ret = v;
	for (int i = 1; i <= k; i++)
	{
		ret = rev(ret, q);
		if (ret == key)
		{
			t2 = i;
			if (i & 1) flag1 = 1;
			else flag2 = 1;
			break;
		}
	}
	if (t1 == 1 && t2 == 1 && k > 1) puts("NO");
	else if (flag1 && k % 2 == 1) puts("YES");
	else if (flag2 && k % 2 == 0) puts("YES");
	else puts("NO");
	return 0;
}