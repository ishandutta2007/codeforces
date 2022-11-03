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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<tuple<int, int, int>> vp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	while (n--)
	{
		int l, r, cost;
		cin >> l >> r >> cost;
		vp[r - l + 1].push_back({ l, cost , cost });
	}
	for (int i = 0; i <= k; i++)
	{
		if (!vp[i].empty())
		{
			sort(vp[i].begin(), vp[i].end());
			int minv = INF;
			for (int j = vp[i].size() - 1; j >= 0; j--)
			{
				minv = min(get<1>(vp[i][j]), minv);
				int &o = get<2>(vp[i][j]);
				o = minv;
			}
		}
	}
	int ans = INF*2;
	for (int i = 0; i <= k; i++)
	{
		auto &v1 = vp[i];
		auto &v2 = vp[k - i];
		int ptr = 0;
		for (auto &p : v1)
		{
			while (ptr < v2.size() && get<0>(v2[ptr]) < get<0>(p) + i)
			{
				ptr++;
			}
			if (ptr == v2.size()) break;
			ans = min(ans, get<1>(p) + get<2>(v2[ptr]));
		}
	}
	if (ans == 2*INF) ans = -1;
	cout << ans << endl;
	return 0;
}