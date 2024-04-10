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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
char str[N];
int sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v;
	LL n;
	int k;
	cin >> n >> k;
	map<int, int> mc;
	for (int i = 0; n >> i; i++)
	{
		if (n >> i & 1)
			mc[i] = 1;
	}
	if (mc.size() > k)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	int cnt = mc.size();
	while (cnt < k)
	{
		auto iter = mc.rbegin();
		if (iter->second + cnt > k) break;
		else
		{
			cnt += iter->second;
			int x = iter->first;
			mc[x - 1] += iter->second * 2;
			mc.erase(x);
		}
	}
	vector<int> ans;
	for (auto& p : mc)
	{
		while (p.second--)
			ans.push_back(p.first);
	}
	reverse(ans.begin(), ans.end());
	while (ans.size() < k)
	{
		int x = ans.back();
		ans.back()--;
		ans.push_back(x - 1);
	}
	for (auto& x : ans)
		printf("%d ", x);
	return 0;
}