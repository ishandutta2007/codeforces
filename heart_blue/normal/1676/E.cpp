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
const int N = 2e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, q;
		scanf("%d%d", &n, &q);
		vector<int> v(n);
		for (auto& x : v)
			scanf("%d", &x);
		sort(v.rbegin(), v.rend());
		for (int i = 1; i < v.size(); i++)
			v[i] += v[i - 1];
		while (q--)
		{
			int x;
			scanf("%d", &x);
			auto iter = lower_bound(v.begin(), v.end(), x);
			if (iter == v.end())
			{
				puts("-1");
			}
			else
			{
				printf("%d\n", iter - v.begin() + 1);
			}
		}
	}

	return 0;
}