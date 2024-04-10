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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, l, r, s;
		cin >> n >> l >> r >> s;
		int sz = r - l + 1;
		int key = n - sz;
		if (n * (n + 1) / 2 - key * (key + 1) / 2 < s || sz * (sz + 1) / 2 > s)
		{
			puts("-1");
			continue;
		}
		s -= sz * (sz + 1) / 2;
		int maxv = n;
		set<int> sp;
		for (int i = 1; i <= n; i++)
		{
			sp.insert(i);
		}
		for (int i = r; i >= l; i--)
		{
			a[i] = i - l + 1;
			int o = min(maxv - a[i], s);
			a[i] += o;
			s -= o;
			maxv--;
			sp.erase(a[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			if (i < l || i > r)
			{
				a[i] = *sp.begin();
				sp.erase(*sp.begin());
			}
			printf("%d ", a[i]);
		}
		puts("");
	}
	return 0;
}