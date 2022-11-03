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
void build(map<int, int>& mc)
{
	string str;
	getline(cin, str);
	stringstream sin(str);
	int x;
	while (sin >> x)
	{
		mc[x] = 1;
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
		int n, x;
		scanf("%d%d", &n, &x);
		vector<pair<int, LL>> vp;
		LL sum = 0;
		for (int i = 1; i <= n; i++)
		{
			int a;
			scanf("%d", &a);
			vp.emplace_back(a, 1);
			sum += a;
		}
		for (int i = 0; i < vp.size(); i++)
		{
			auto [val, cnt] = vp[i];
			if (val % x) break;
			sum += val * cnt;
			vp.emplace_back(val / x, x * cnt);
		}
		printf("%lld\n", sum);
	}
	return 0;
}