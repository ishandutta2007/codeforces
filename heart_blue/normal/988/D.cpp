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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<LL> v;
	for (int i = 0; i < 33; i++) v.push_back(1LL << i);
	int n;
	map<LL, int> mc;
	cin >> n;
	vector<LL> ans;
	for (int i = 0; i < n; i++)
	{
		LL x;
		cin >> x;
		mc[x] = 1;
	}
	ans.push_back({ mc.begin()->first });
	for (auto &p : mc)
	{
		LL y = p.first;
		for (auto &x : v)
		{
			if (mc.count(y - x) && mc.count(y + x))
			{
				cout << 3 << endl;
				cout << y - x << ' ' << y << ' ' << y + x << endl;
				return 0;
			}
			if (mc.count(y - x))
			{
				ans = { y - x,y };
			}
			if (mc.count(y + x))
			{
				ans = { y,y + x };
			}
		}
	}
	cout << ans.size() << endl;
	for (auto &x : ans) cout << x << ' ';
	return 0;
}