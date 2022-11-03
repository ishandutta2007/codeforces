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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	map<int, int> mc;
	mc[0] = 0;
	for (int i = 2; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
		mc[a[i]] = 1;
	}
	if (mc.size() != n || mc.rbegin()->first - mc.begin()->first != n - 1) puts("-1"), exit(0);
	int offset = n - mc.rbegin()->first;
	for (int i = 1; i <= n; i++) printf("%d ", a[i] + offset);
	return 0;
}