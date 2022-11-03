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
const int N = 2e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> v(m);
	for (auto& x : v) scanf("%*d%d", &x);
	sort(v.rbegin(), v.rend());
	int tot = 0;
	for (int i = 1; i < N; i += 2)
	{
		int sum = i * (i - 1) / 2;
		if (sum + 1 > n) break;
		tot = i;
	}
	for (int i = 2; i < N; i += 2)
	{
		int sum = i * (i - 1) / 2 - (i - 2) / 2;
		if (sum + 1 + (i - 2) > n) break;
		tot = max(tot, i);
	}
	LL ans = 0;
	for (int i = 0; i < min(tot, m); i++)
	{
		ans += v[i];
	}
	cout << ans << endl;
	return 0;
}