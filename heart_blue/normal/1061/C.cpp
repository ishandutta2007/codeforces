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
const int N = 1e5 + 10;
vector<pair<int, int>> vp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	for (int i = 0; i < N; i++) vp[i].emplace_back(0, 0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		for (int o = 1; o * o <= x; o++)
		{
			if (x % o) continue;
			vp[o].emplace_back(i, 0);
			if (o * o != x && x / o < N) vp[x / o].emplace_back(i, 0);
		}
	}
	vp[0][0].second = 1;
	LL ans = 0;
	for (int i = 1; i < N; i++)
	{
		auto& v1 = vp[i - 1];
		auto& v2 = vp[i];
		int cur = 0;
		int ptr = 0;
		int sum = 0;
		for (auto& p : v2)
		{
			while (ptr < v1.size() && v1[ptr].first < p.first)
			{
				cur = v1[ptr].second;
				ptr++;
			}
			p.second = (cur + sum) % INF;
			sum = p.second;
		}
		ans += v2.back().second;
	}
	cout << ans % INF << endl;
	return 0;
}