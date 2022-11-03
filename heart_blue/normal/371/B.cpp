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
const int N = 4e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b;
	cin >> a >> b;
	function<int(int,int)> gcd = [&](int n, int m) -> int
	{
		return m == 0 ? n : gcd(m, n%m);
	};
	auto check = [](int x) -> int
	{
		int a[3] = { 2,3,5 };
		int cnt = 0;
		for (int i = 0; i < 3; i++) while (x % a[i] == 0) x /= a[i], cnt++;
		if (x != 1) cnt = -INF;
		return cnt;
	};
	int g = gcd(a, b);
	int ans = check(a / g) + check(b / g);
	if (ans < 0) ans = -1;
	cout << ans << endl;
	return 0;
}