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
const int N = 2e5 + 10;
bool check(int x)
{
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0) return false;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, int>> ans;
	for (int i = 1; i < n; i++) ans.emplace_back(i, i + 1);
	ans.emplace_back(1, n);
	int l = 1, r = n / 2 + 1;
	while (!check(ans.size()))
	{
		ans.emplace_back(l++, r++);
	}
	cout << ans.size() << endl;
	for (auto& p : ans)
		cout << p.first << ' ' << p.second << endl;
	return 0;
}