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
#include <cassert>
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int k;
		cin >> k;
		vector<int> v(k);
		for (auto &x : v) cin >> x;
		sort(v.begin(), v.end(), [](int x, int y) -> bool
		{
			return abs(x) < abs(y);
		});
		int flag = 0;
		for (int i = 1; i < k; i++)
		{
			if (v[i] + v[i - 1] == 0)
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}