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
#include <chrono>
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
	int n;
	scanf("%d", &n);
	vector<int> v;
	int pre = -1;
	int maxv = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		maxv = max(maxv, x);
		if (v.empty())
		{
			v.push_back(x);
			pre = -1;
			continue;
		}
		if (v.back() == x && v.back() >= pre)
		{
			pre = v.back();
			v.pop_back();
		}
		else
		{
			v.push_back(x);
			pre = -1;
		}
	}
	if (v.size() > 1) puts("NO");
	else if (v.empty() || maxv == v[0]) puts("YES");
	else puts("NO");
	return 0;
}