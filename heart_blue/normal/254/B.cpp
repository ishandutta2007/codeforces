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
int day[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int getday(int m, int d)
{
	return day[m - 1] + d;
}
int a[N];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	for (int i = 1; i < 13; i++) day[i] += day[i - 1];
	vector<pair<pair<int, int>,int>> vp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m, d, p, t;
		cin >> m >> d >> p >> t;
		d = getday(m, d);
		vp.push_back({ {d - t,d}, p });
	}
	sort(vp.begin(), vp.end());
	int ptr = 0;
	int tot = 0;
	int ans = 0;
	for (auto &p : vp)
	{
		int l, r;
		tie(l, r) = p.first;
		while (ptr <= l) tot += a[ptr++];
		ans += max(0, p.second - tot);
		a[r] += p.second;
		tot = max(0, tot - p.second);
	}
	cout << ans << endl;
	return 0;
}