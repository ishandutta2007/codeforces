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
const int N = 3e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, s, k;
		cin >> n >> s >> k;
		map<int, int> mc;
		for (int i = 1; i <= k; i++)
		{
			int x;
			cin >> x;
			mc[x] = 1;
		}
		int ans = INF;
		for (int i = max(1, s - 2 * k); i <= min(n, s + 2 * k); i++)
		{
			if (mc.count(i)) continue;
			ans = min(ans, abs(s - i));
		}
		cout << ans << endl;
	}
	return 0;
}