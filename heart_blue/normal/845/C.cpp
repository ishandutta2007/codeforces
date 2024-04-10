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
const int N = 1e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, int>> vp(n);
	for (auto &p : vp)
	{
		cin >> p.first >> p.second;
	}
	sort(vp.begin(), vp.end());
	int o1 = -1, o2 = -1;
	for (auto &p : vp)
	{
		if (p.first > o1) o1 = p.second;
		else
		{
			puts("NO");
			return 0;
		}
		if (o1 > o2) swap(o1, o2);
	}
	puts("YES");
	return 0;
}