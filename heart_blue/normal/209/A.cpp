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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int cnt[2] = { 0,0 };
	int ans = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int o = i & 1;
		cnt[o] += 1 + cnt[o ^ 1];
		ans += 1 + cnt[o ^ 1];
		if (cnt[o] >= INF) cnt[o] -= INF;
		if (ans >= INF) ans -= INF;
	}
	cout << ans << endl;
	return 0;
}