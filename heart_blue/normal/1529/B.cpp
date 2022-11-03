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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		vector<int> v(n);
		for (auto& x : v)
			scanf("%d", &x);
		int ans = 0;
		sort(v.begin(), v.end());
		int key = INF * 2 + 10;
		for (auto& x : v)
		{
			if (x <= 0) ans++;
			else
			{
				key = x;
				break;
			}
		}
		ans = max(ans, 1);
		while (!v.empty() && v.back() >= key)
		{
			v.pop_back();
		}
		int minv = INF * 2;
		for (int i = 1; i < v.size(); i++)
		{
			minv = min(v[i] - v[i - 1], minv);
		}
		if (minv >= key) ans = v.size() + 1;
		printf("%d\n", ans);

	}
	return 0;
}