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
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		v[i].resize(2);
		cin >> v[i][0] >> v[i][1];
	}
	vector<int> ans;
	ans.push_back(1);
	map<int, int> mc;
	while (ans.size() < n)
	{
		int x = ans.back();
		mc[x] = 1;
		for (auto& y : v[x])
		{
			if (mc.count(y)) continue;
			int z = y ^ v[x][0] ^ v[x][1];
			if (find(v[y].begin(), v[y].end(), z) != v[y].end())
			{
				ans.push_back(y);
				break;
			}
		}
	}
	for (auto& x : ans) cout << x << ' ';
	return 0;
}