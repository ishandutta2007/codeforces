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
const int N = 5e5 + 10;
LL fact[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	fact[0] = 1;
	for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % m;
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += fact[i] * (n - i + 1)%m * (n - i + 1)%m * fact[n - i]%m;
		if (ans >= m) ans -= m;
	}
	cout << ans << endl;
	return 0;
}