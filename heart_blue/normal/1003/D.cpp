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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	cin >> n >> q;
	map<int, int> mc;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		mc[x]++;
	}
	vector<pair<int, int>> vp;
	for (auto &p : mc) vp.push_back(p);
	reverse(vp.begin(), vp.end());
	while (q--)
	{
		int x;
		cin >> x;
		int tot = 0;
		for (auto &p : vp)
		{
			int r = min(p.second, x / p.first);
			x -= r * p.first;
			tot += r;
		}
		if (x != 0) tot = -1;
		printf("%d\n", tot);
	}
	return 0;
}