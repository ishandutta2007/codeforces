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
const int N = 2e5 + 10;
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	map<int, pair<int, int>> mc;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int sz;
		cin >> sz;
		v[i].resize(sz);
		int sum = 0;
		for (auto &x : v[i]) cin >> x, sum += x;
		for (int j = 0; j < sz; j++)
		{
			int r = sum - v[i][j];
			if (mc.count(r))
			{
				cout << "YES" << endl;
				cout << i << ' ' << j + 1 << endl;
				cout << mc[r].first << ' ' << mc[r].second << endl;
				return 0;
			}
		}
		for (int j = 0; j < sz; j++)
		{
			mc[sum - v[i][j]] = { i,j + 1 };
		}
	}
	puts("NO");
	return 0;
}