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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int ans[N];
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
		vector<tuple<int, int, int>> vp;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			vp.emplace_back(0, x, i);
		}
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			get<0>(vp[i]) = str[i] - '0';
		}
		sort(vp.begin(), vp.end());
		for (int i = 0; i < n; i++)
		{
			int id = get<2>(vp[i]);
			ans[id] = i + 1;
		}
		for (int i = 1; i <= n; i++)
			printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}