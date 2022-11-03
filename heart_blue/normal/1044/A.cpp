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
const int N = 5e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> v1(n);
	for (auto& x : v1)
		cin >> x;
	vector<int> v2;
	while (m--)
	{
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		if (x1 != 1) continue;
		v2.push_back(x2);
	}
	v1.push_back(int(1e9));
	n++;
	sort(v1.rbegin(), v1.rend());
	sort(v2.rbegin(), v2.rend());
	int ans = INF;
	while (!v1.empty())
	{
		while (!v2.empty() && v2.back() < v1.back()) v2.pop_back();
		ans = min(ans, int(n - v1.size()) + (int)v2.size());
		v1.pop_back();
	}
	printf("%d\n", ans);
	return 0;
}