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
const int N = 2e5 + 20;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, r;
	cin >> n >> r;
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x == 1) v.push_back(i);
	}
	int cur = 1;
	int ans = 0;
	while (cur <= n)
	{
		int key = -1;
		for (auto &x : v)
		{
			if (abs(x - cur) <= r - 1)
			{
				key = x;
			}
		}
		if (key == -1)
		{
			puts("-1");
			return 0;
		}
		ans++;
		cur = key + r;
	}
	cout << ans << endl;
	return 0;
}