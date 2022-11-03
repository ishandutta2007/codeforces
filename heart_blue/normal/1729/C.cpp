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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string str;
		cin >> str;
		int n = str.length();
		int lo = str[0];
		int up = str[n - 1];
		int flag = 0;
		if (lo > up) swap(lo, up), flag = 1;
		vector<pair<int, int>> vp;
		for (int i = 1; i + 1 < n; i++)
		{
			if (str[i] >= lo && str[i] <= up)
				vp.emplace_back(str[i], i + 1);
		}
		sort(vp.begin(), vp.end());
		if (flag)
			reverse(vp.begin(), vp.end());
		vector<int> ans;
		ans.push_back(1);
		for (auto [c, id] : vp)
			ans.push_back(id);
		ans.push_back(n);
		printf("%d %d\n", up - lo, ans.size());
		for (int i = 0; i < ans.size(); i++)
			printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
	}
	return 0;
}