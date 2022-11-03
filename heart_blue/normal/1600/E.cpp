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
const int N = 2e5 + 10;

int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	vector<int> v1, v2;
	for (int i = 1; i <= n; i++)
	{
		if (v1.empty()) v1.push_back(a[i]);
		else if (v1.back() < a[i]) v1.push_back(a[i]);
		else break;
	}
	for (int i = n; i >= 1; i--)
	{
		if (v2.empty()) v2.push_back(a[i]);
		else if (v2.back() < a[i]) v2.push_back(a[i]);
		else break;
	}
	int o = 1;
	reverse(v1.begin(), v1.end());
	reverse(v2.begin(), v2.end());
	int last = -1;
	while (!v1.empty() || !v2.empty())
	{
		if (!v1.empty() && v1.back() <= last) v1.clear();
		if (!v2.empty() && v2.back() <= last) v2.clear();
		if (v1.empty() && v2.empty()) break;
		o ^= 1;
		if (v1.empty())
		{
			v2.pop_back();
			continue;
		}
		if (v2.empty())
		{
			v1.pop_back();
			continue;
		}
		if (v1.back() >= v2.back() && v1.size() % 2 == 1)
		{
			v1.pop_back();
			v2.clear();
			continue;
		}
		if (v2.back() >= v1.back() && v2.size() % 2 == 1)
		{
			v2.pop_back();
			v1.clear();
			continue;
		}
		if (v1.back() <= v2.back()) v1.pop_back();
		else v2.pop_back();
	}
	if (o) puts("Bob");
	else puts("Alice");
	return 0;
}