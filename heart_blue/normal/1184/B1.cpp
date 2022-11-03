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
int ans[N];
int a[N];
pair<int, LL> b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i].first >> b[i].second;
	sort(b + 1, b + m + 1);
	b[m + 1].first = INF * INF;
	for (int i = 1; i <= m; i++) b[i].second += b[i - 1].second;
	for (int i = 1; i <= n; i++)
	{
		auto iter = upper_bound(b + 1, b + m + 1, make_pair(a[i], INF * INF)) - 1;
		cout << iter->second << ' ';
	}
	return 0;
}