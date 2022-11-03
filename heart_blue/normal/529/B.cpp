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
int a[N], b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int maxv = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		maxv = max(maxv, min(a[i], b[i]));
	}
	int ans = INF;
	for (int h = maxv; h <= 1000; h++)
	{
		int sum = 0;
		int cnt = 0;
		vector<int> v;
		for (int i = 1; i <= n; i++)
		{
			if (b[i] <= h)
			{
				sum += a[i] * h;
				if (a[i] <= h) v.push_back(b[i] * h - a[i] * h);
			}
			else sum += b[i] * h, cnt++;
		}
		sort(v.rbegin(), v.rend());
		while ((cnt + 1) * 2 <= n && !v.empty() && v.back() < 0)
		{
			sum += v.back();
			v.pop_back();
			cnt++;
		}
		if (cnt * 2 <= n) ans = min(ans, sum);
	}
	cout << ans << endl;
	return 0;
}