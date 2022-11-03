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
const int N = 5e2 + 10;
vector<int> solve(int l, int r, int& k)
{
	k--;
	if (k == 0 || l + 1 == r)
	{
		vector<int> v;
		for (int i = 1; i <= r - l; i++)
			v.push_back(i);
		return v;
	}
	int mid = (l + r) / 2;
	k--;
	auto ret1 = solve(l, mid, k);
	k++;
	auto ret2 = solve(mid, r, k);
	vector<int> ret;
	for (auto& x : ret1) ret.push_back(x + ret2.size());
	for (auto& x : ret2) ret.push_back(x);
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	auto ret = solve(0, n, k);
	if (k) puts("-1");
	else
	{
		for (auto& x : ret)
			printf("%d ", x);
	}
	return 0;
}