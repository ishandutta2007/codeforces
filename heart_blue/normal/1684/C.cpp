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
#include <complex>
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v[N];
void refrain(vector<int>& v, vector<int>& ret)
{
	vector<int> key = v;
	sort(key.begin(), key.end());
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] != key[i])
			ret.push_back(i);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		vector<int> key;
		for (int i = 0; i < n; i++)
		{
			v[i].clear();
			v[i].resize(m);
			for (auto& y : v[i])
				scanf("%d", &y);
			refrain(v[i], key);
		}
		sort(key.begin(), key.end());
		key.resize(unique(key.begin(), key.end()) - key.begin());
		if (key.size() > 2)
		{
			puts("-1");
		}
		else if (key.empty())
		{
			puts("1 1");
		}
		else
		{
			int x = key[0], y = key[1];
			int flag = 1;
			for (int i = 0; i < n; i++)
			{
				swap(v[i][x], v[i][y]);
				if (!is_sorted(v[i].begin(), v[i].end()))
					flag = 0;
			}
			if (flag) printf("%d %d\n", key[0] + 1, key[1] + 1);
			else puts("-1");
		}
	}
	return 0;
}