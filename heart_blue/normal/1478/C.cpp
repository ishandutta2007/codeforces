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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		cin >> n;
		map<LL, int> mc;
		int flag = 1;
		for (int i = 0; i < 2 * n; i++)
		{
			LL x;
			scanf("%lld", &x);
			mc[x]++;
			if (x % 2 == 1 || x == 0) flag = 0;
		}
		vector<LL> v;
		for (auto& p : mc)
		{
			if (p.second > 2 || p.second % 2 == 1)
			{
				flag = 0;
				break;
			}
			v.push_back(p.first);
		}
		if (flag == 0)
		{
			puts("NO");
			continue;
		}
		vector<LL> ans;
		ans.push_back(0);
		LL sum = 0;
		for (int i = 1; i < v.size(); i++)
		{
			LL dif = (v[i] - v[i - 1]) / 2;
			if (dif % i)
			{
				flag = 0;
				break;
			}
			ans.push_back(ans.back() + dif / i);
			sum += ans.back();
		}
		if (flag == 0)
		{
			puts("NO");
			continue;
		}
		LL tot = v[0] / 2;
		if (tot <= sum || (tot - sum) % n != 0) puts("NO");
		else puts("YES");
	}

	return 0;
}