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
const int N = 5e3 + 10;
pair<int, int> refrain(int l1, int r1, int l2, int r2)
{
	int l = max(l1, l2);
	int r = min(r1, r2);
	return make_pair(l, r);
}
LL combine(const pair<int, int>& p1, const pair<int, int>& p2)
{
	int l1, r1;
	int l2, r2;
	tie(l1, r1) = p1;
	tie(l2, r2) = p2;
	int cnt1 = max(0, r1 - l1 + 1);
	int cnt2 = max(0, r2 - l2 + 1);
	return 1LL * cnt1 * cnt2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v;
	v.push_back(0);
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] * 10LL > INF) continue;
		v.push_back(v[i] * 10 + 4);
		v.push_back(v[i] * 10 + 7);
	}
	v.push_back(2 * INF);
	int l1, r1, l2, r2;
	int k;
	cin >> l1 >> r1 >> l2 >> r2 >> k;
	LL ans = 0;
	for (int i = 1; i + k < v.size(); i++)
	{
		ans += combine(refrain(l1,r1,v[i-1]+1,v[i]),
			refrain(l2, r2, v[i + k - 1], v[i + k] - 1));
		ans += combine(refrain(l2, r2, v[i - 1] + 1, v[i]),
			refrain(l1, r1, v[i + k - 1], v[i + k] - 1));
		if (k == 1)
			ans -= combine(refrain(l1, r1, v[i], v[i]),
				refrain(l2, r2, v[i], v[i]));
	}
	printf("%.15f\n", 1.0 * ans / (r1 - l1 + 1) / (r2 - l2 + 1));
	return 0;
}