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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v)
		{
			cin >> x;
			x /= 100;
		}
		sort(v.rbegin(), v.rend());
		int x, a, y, b;
		cin >> x >> a >> y >> b;
		LL k;
		cin >> k;
		int ans = -1;
		int l = 1, r = n;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			vector<int> vp;
			for (int i = 1; i <= mid; i++)
			{
				int o = 0;
				if (i % a == 0) o += x;
				if (i % b == 0) o += y;
				if (o) vp.emplace_back(o);
			}
			sort(vp.rbegin(), vp.rend());
			LL tot = 0;
			for (int i = 0; i < vp.size(); i++)
			{
				tot += vp[i] * v[i];
			}
			if (tot >= k) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}