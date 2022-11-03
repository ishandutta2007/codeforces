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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	int k;
	scanf("%d", &k);
	if (1LL * n * (n + 1) / 2 < k)
	{
		puts("No such line.");
		return 0;
	}
	vector<pair<char, int>> vp1;
	for (int i = 1; i <= n; i++)
		vp1.emplace_back(str[i], i);
	string ans;
	while (k > 0)
	{
		sort(vp1.begin(), vp1.end());
		auto vp2 = vp1;
		LL tot = 0;
		char c = 'a';
		for (int i = 0; i < vp2.size(); i++)
		{
			tot += n - vp2[i].second + 1;
			if (tot >= k)
			{
				c = vp2[i].first;
				break;
			}
		}
		ans += c;
		vp1.clear();
		for (auto [ch, x] : vp2)
		{
			if (c > ch)
				k -= n - x + 1;
			if (c == ch)
			{
				k--;
				if (x != n)
					vp1.emplace_back(str[x + 1], x + 1);
			}
		}

	}
	puts(ans.c_str());
	return 0;
}