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
		int n, k;
		scanf("%d%d", &n, &k);
		map<int, int> mc;
		vector<int> v;
		while (n--)
		{
			int x;
			scanf("%d", &x);
			mc[x]++;
		}
		for (auto& [x, cnt] : mc)
		{
			if (cnt >= k)
				v.push_back(x);
		}
		tuple<int, int, int> ans = { -1,-1,-1 };
		for (int i = 0; i < v.size(); i++)
		{
			int j = i;
			while (j < v.size() && v[j] - v[i] == j - i)
				j++;
			ans = max(ans, { j - i,v[i],v[j - 1] });
			i = j - 1;
		}
		auto [tot, l, r] = ans;
		if (tot == -1) puts("-1");
		else printf("%d %d\n", l, r);

	}

	return 0;
}