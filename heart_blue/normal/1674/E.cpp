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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int check(int a, int b)
{
	if (a < b) swap(a, b);
	int o = min({ b,a - b });
	a -= o * 2, b -= o;
	if (b == 0) return (a + 1) / 2 + o;
	else return o + a / 3 * 2 + a % 3;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	int ans = INF;
	for (auto& x : v)
		scanf("%d", &x);
	for (int i = 0; i + 1 < v.size(); i++)
		ans = min(ans, check(v[i], v[i + 1]));
	for (int i = 1; i + 1 < v.size(); i++)
		ans = min(ans, (v[i - 1] + v[i + 1] + 1) / 2);
	sort(v.begin(), v.end());
	ans = min(ans, (v[0] + 1) / 2 + (v[1] + 1) / 2);
	printf("%d\n", ans);
	return 0;
}