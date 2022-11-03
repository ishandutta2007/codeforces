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
const int N = 2e5 + 10;
int a[N];
LL C(int n, int m)
{
	LL ret = 1;
	LL div = 1;
	while (m)
	{
		ret *= n--;
		div *= m--;
	}
	return ret / div;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	map<int, int> mc;
	for (int i = 1; i <= n; i++) cin >> a[i], mc[a[i]]++;
	int o = 3;
	LL ans = 1;
	for (auto &p : mc)
	{
		if (o == 0) break;
		int r = min(p.second, o);
		o -= r;
		ans *= C(p.second, r);
	}
	cout << ans << endl;
	return 0;
}