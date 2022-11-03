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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	if (n == 1)
	{
		puts("1 0");
		return 0;
	}
	vector<int> v;
	int res = 1;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i) continue;
		int cnt = 0;
		while (n % i == 0) n /= i, cnt++;
		v.push_back(cnt);
		res *= i;
	}
	if (n > 1) v.push_back(1), res *= n;
	sort(v.begin(), v.end());
	int ans = v.front() != v.back();
	int x = v.back();
	map<int, int> mc;
	mc[1] = 1;
	mc[2] = 1;
	mc[4] = 1;
	mc[8] = 1;
	mc[16] = 1;
	mc[32] = 1;
	ans = min(ans + !mc.count(x), 1);
	if (x <= 1) x = 1;
	else if (x <= 2) x = 2;
	else if (x <= 4) x = 4;
	else if (x <= 8) x = 8;
	else if (x <= 16) x = 16;
	else x = 32;
	while (x > 1) x >>= 1, ans++;
	cout << res << ' ' << ans << endl;
	return 0;
}