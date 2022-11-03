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
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int l = 1;
	int r = n - 1;
	vector<int> ans;
	int cur = 1;
	while (l <= r)
	{
		while (gcd(l, n) > 1) l++;
		while (gcd(r, n) > 1) r--;
		if (l > r) break;
		ans.push_back(l);
		if (l != r) ans.push_back(r);
		cur = 1LL * cur * r * l % n;
		l++, r--;
	}
	sort(ans.begin(), ans.end());
	if (cur != 1)
		ans.pop_back();
	printf("%d\n", ans.size());
	for (auto& x : ans)
		printf("%d ", x);
	return 0;
}