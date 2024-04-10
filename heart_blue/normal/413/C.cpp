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
	int n, m;
	cin >> n >> m;
	LL ans = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], ans += a[i];
	vector<int> v;
	for (int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		ans -= a[x];
		v.push_back(a[x]);
	}
	sort(v.rbegin(), v.rend());
	for (auto& x : v)
	{
		if (ans >= x) ans *= 2;
		else ans += x;
	}
	cout << ans << endl;
	return 0;
}