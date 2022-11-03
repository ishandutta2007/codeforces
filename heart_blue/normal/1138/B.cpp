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
vector<int> v[4];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;
	for (int i = 0; i < n; i++)
	{
		v[(s2[i] - '0') << 1 | (s1[i] - '0')].push_back(i + 1);
	}
	for (int i = 0; i <= v[1].size(); i++)
	{
		for (int j = 0; j <= v[3].size(); j++)
		{
			int a0, a1 = i, a2, a3 = j;
			int b0, b1 = v[1].size() - a1, b2, b3 = v[3].size() - a3;
			b2 = a1 + a3 - b3;
			if (b2 < 0 || b2 > v[2].size()) continue;
			a2 = v[2].size() - b2;
			a0 = n / 2 - a1 - a2 - a3;
			b0 = n / 2 - b1 - b2 - b3;
			if (a0 < 0 || a0 > v[0].size()) continue;
			if (b0 < 0 || b0 > v[0].size()) continue;
			if (a1 + a3 != b2 + b3) continue;
			int a[4] = { a0,a1,a2,a3 };
			for (int o = 0; o < 4; o++)
			{
				for (int k = 0; k < a[o]; k++) printf("%d ", v[o][k]);
			}
			return 0;
		}
	}
	puts("-1");
	return 0;
}