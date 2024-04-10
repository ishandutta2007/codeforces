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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
vector<pair<LL, LL>> vp;
LL check(int k)
{
	if (k == 0) return 0;
	nth_element(vp.begin(), vp.begin() + k - 1, vp.end(), [&](pair<LL, LL> &p1, pair<LL, LL> &p2) -> bool
	{
		return p1.first + p1.second*k < p2.first + p2.second*k;
	});
	LL tot = 0;
	for (int i = 0; i < k; i++) tot += vp[i].first + vp[i].second*k;
	return tot;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, s;
	cin >> n >> s;
	for (LL i = 1; i <= n; i++)
	{
		LL x;
		cin >> x;
		vp.push_back({ x,i });
	}
	int l = 1, r = n;
	LL ret = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid) <= s) ret = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ret << ' ' << check(ret) << endl;
	return 0;
}