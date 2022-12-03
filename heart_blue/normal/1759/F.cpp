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
		int n, b;
		scanf("%d%d", &n, &b);
		vector<int> v(n + 1, 0);
		set<int> s;
		for (int i = 1; i <= n; i++)
			scanf("%d", &v[i]), s.emplace(v[i]);
		if (s.size() == b)
		{
			puts("0");
			continue;
		}
		int last = v.back();
		int kx = -1;
		for (int i = b - 1; i >= last; i--)
		{
			if (s.count(i) == 0)
			{
				kx = i;
				break;
			}
		}
		int ky = -1;
		for (int i = last - 1; i >= 0; i--)
		{
			if (s.count(i) == 0)
			{
				ky = i;
				break;
			}
		}
		if (kx != -1 && ky == -1)
		{
			printf("%d\n", kx - last);
			continue;
		}
		int ans = b - last;
		v[n] = 0;
		v[n - 1]++;
		s.insert(0);
		for (int i = n - 1; i > 0; i--)
		{
			v[i - 1] += v[i] / b;
			v[i] %= b;
			s.insert(v[i]);
		}
		if (v[0] == 1)
			s.insert(1);
		ky = -1;
		for (int i = last; i >= 0; i--)
		{
			if (s.count(i) == 0)
			{
				ky = i;
				break;
			}
		}
		if (ky != -1) ans += ky;
		printf("%d\n", ans);
	}
	return 0;
}