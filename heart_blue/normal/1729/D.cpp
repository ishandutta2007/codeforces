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
int a[N];
int b[N];
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
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		vector<int> v1, v2;
		for (int i = 1; i <= n; i++)
		{
			int x = b[i] - a[i];
			if (x >= 0) v1.push_back(x);
			else v2.push_back(-x);
		}
		sort(v1.rbegin(), v1.rend());
		sort(v2.begin(), v2.end());
		int ans = 0;
		for (auto& x : v1)
		{
			while (!v2.empty() && x < v2.back())
			{
				v2.pop_back();
			}
			if (v2.empty()) break;
			ans++;
			v2.pop_back();
		}
		printf("%d\n", ans + (v1.size() - ans) / 2);
	}
	return 0;
}