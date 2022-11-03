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
const int N = 4e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, a, b;
		scanf("%d%d", &a, &b);
		n = a + b;
		int sz1 = (n + 1) / 2;
		int sz2 = n - sz1;
		vector<int> v;
		for (int o = 0; o < 2; o++)
		{
			swap(sz1, sz2);
			for (int i = 0; i <= sz1; i++)
			{
				if (i > a) break;
				if (a - i > sz2) continue;
				v.push_back(sz1 - i + a - i);
			}
		}
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());
		printf("%d\n", v.size());
		for (auto& x : v)
			printf("%d ", x);
		puts("");
	}
	return 0;
}