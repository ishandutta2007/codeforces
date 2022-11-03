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
const int N = 3e3 + 10;
int a[N];
int b[N];
int flag[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> v;
	int cur = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (i == k) cur += x;
		else v.push_back(x);
	}
	set<pair<int,int>> s;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (i == 1) cur += x;
		else s.emplace(x, i);
	}
	int ans = 1;
	for (auto& x : v)
	{
		if (x + s.begin()->first > cur)
		{
			ans++;
			s.erase(*s.rbegin());
			continue;
		}
		auto iter = s.upper_bound(make_pair(cur - x, n + 1));
		iter--;
		s.erase(*iter);
	}
	cout << ans << endl;
	return 0;
}