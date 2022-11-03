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
		vector<tuple<int, int, int>> vp;
		int n;
		scanf("%d", &n);
		vector<int> v(n);
		for (auto& x : v)
			scanf("%d", &x);
		for (int i = 0; i < n; i++)
		{
			int id = min_element(v.begin() + i, v.end()) - v.begin();
			if (id == i) continue;
			vp.emplace_back(i + 1, id + 1, id - i);
			int x = v[id];
			for (int j = id; j > i; j--)
				v[j] = v[j - 1];
			v[i] = x;
		}
		printf("%d\n", vp.size());
		for (auto [l, r, d] : vp)
		{
			printf("%d %d %d\n", l, r, d);
		}
	}
	return 0;
}