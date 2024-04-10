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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
vector<pair<int, int>> vp[2];
vector<int> key[2];
bool check(vector<pair<int, int>>& vp, vector<int>& key, int a)
{
	if (vp.empty()) return false;
	for (auto& x : key)
	{
		if (x != a)
		{
			auto [o1, o2] = vp.back();
			vp.pop_back();
			cout << x << ' ' << o1 << ' ' << o2 << endl;
			return true;
		}
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			vp[(i + j) & 1].emplace_back(i, j);
		}
	}
	key[0].push_back(1);
	key[1].push_back(2);
	for (int i = 1; i <= n * n; i++)
	{
		int a;
		cin >> a;
		if (check(vp[0], key[0], a) || check(vp[1], key[1], a))
			;
		if (vp[0].empty()) key[1].push_back(3);
		if (vp[1].empty()) key[0].push_back(3);
	}
	return 0;
}