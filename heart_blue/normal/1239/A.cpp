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
LL dp2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 2; i < N; i++)
	{
		dp2[i] = (dp2[i - 2] + 1 + dp2[i - 1]) % INF;
	}
	int n, m;
	cin >> n >> m;
	LL ans = 2 * dp2[n] + 2 * dp2[m] + 2;
	ans %= INF;
	if (ans < 0) ans += INF;
	cout << ans << endl;

	return 0;
}