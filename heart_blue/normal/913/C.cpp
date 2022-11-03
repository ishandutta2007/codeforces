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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, l;
	cin >> n >> l;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	for (int i = 1; i < n; i++) a[i] = min(a[i], a[i - 1] * 2);
	LL ans = 0;
	LL res = l * a[0];
	for (int i = n - 1; i >= 0; i--)
	{
		int o = 1 << i;
		res = min(res, ans + (l - 1 + o) / o * a[i]);
		ans += l / o*a[i];
		l %= o;
	}
	cout << res << endl;
	return 0;
}