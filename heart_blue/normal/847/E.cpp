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
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
vector<int> v1, v2;
char str[N];
bool check(int cost)
{
	if (v2.empty()) return true;
	int ptr = 0;
	int sz = v2.size();
	for (auto &x : v1)
	{
		if (x - v2[ptr] > cost) return false;
		int c = cost;
		if (x >= v2[ptr])
		{
			c = max(c - 2 * (x - v2[ptr]), (c - (x - v2[ptr])) / 2);
			while (ptr < sz && v2[ptr] <= x) ptr++;

		}
		while (ptr < sz && v2[ptr] <= x + c) ptr++;
		if (ptr == sz) return true;
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	scanf("%s", str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'P') v1.push_back(i);
		else if (str[i] == '*') v2.push_back(i);
	}
	int l = 0, r = n*3;
	int ans = r;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}