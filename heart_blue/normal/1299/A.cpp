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
const int N = 3e5 + 10;
int cnt[40];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	pair<int, int> maxv = { -1,-1 };
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		for (int o = 0; a[i] >> o; o++)
		{
			if (a[i] >> o & 1)
				cnt[o]++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int x = 0;
		for (int o = 0; a[i] >> o; o++)
		{
			if ((a[i] >> o & 1) && cnt[o] == 1)
				x |= 1 << o;
		}
		maxv = max(maxv, make_pair(x, i));
	}
	cout << a[maxv.second];
	for (int i = 1; i <= n; i++)
	{
		if (maxv.second == i) continue;
		cout << ' ' << a[i];
	}

	return 0;
}