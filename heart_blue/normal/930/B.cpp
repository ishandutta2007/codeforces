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
const int N = 5e3 + 10;
map<int, int> mc[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int n = str.length();
	int ans = 0;
	for (int c = 'a'; c <= 'z'; c++)
	{
		for (int i = 0; i < n; i++) mc[i].clear();
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (str[i] != c) continue;
			cnt++;
			for (int j = 0; j < n; j++)
			{
				if (i == j) continue;
				int o = j - i;
				if (o < 0) o += n;
				mc[o][str[j]]++;
			}
		}
		int maxv = 0;
		for (int i = 0; i < n; i++)
		{
			int t = 0;
			for (auto &p : mc[i])
			{
				if (p.second == 1) t++;
			}
			maxv = max(t, maxv);
		}
		ans += maxv;
	}
	printf("%.15f\n", ans*1.0 / n);
	return 0;
}