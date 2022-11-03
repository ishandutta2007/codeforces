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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
map<int, int> m;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int x;
	vector<pair<int, int>> vp;
	scanf("%d", &n);
	int pre = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		if (m.count(x))
		{
			if (m[x] > pre)
			{
				vp.push_back({ pre + 1, i });
				pre = i;
			}
		}
		m[x] = i;
	}
	if (vp.empty()) puts("-1");
	else
	{
		printf("%d\n", vp.size());
		vp.back().second = n;
		for (auto &p : vp)
		{
			printf("%d %d\n", p.first, p.second);
		}
	}
	return 0;
}