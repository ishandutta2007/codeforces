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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	set<pair<int, int>> s;
	cin >> n >> k;
	map<int, int> mc;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (mc.count(x))
		{
			int pos = mc[x];
			if (s.count(make_pair(pos, x)))
				continue;
		}
		if (s.size() == k) s.erase(s.begin());
		s.emplace(i, x);
		mc[x] = i;
	}
	vector<int> v;
	for (auto& p : s)
	{
		v.push_back(p.second);
	}
	reverse(v.begin(), v.end());
	cout << v.size() << endl;
	for (auto& x : v) cout << x << ' ';
	return 0;
}