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
	int a1, a2, k1, k2;
	cin >> a1 >> a2 >> k1 >> k2;
	int n;
	cin >> n;
	cout << max(0, n - (k1 - 1) * a1 - (k2 - 1) * a2) << ' ';
	if (k1 > k2) swap(k1, k2), swap(a1, a2);
	int o = min(a1, n / k1);
	int ans = o + min(a2, (n - o * k1) / k2);
	cout << ans << endl;
	return 0;
}