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
LL fact[N];
LL inv[N];
void init()
{
	fact[0] = 1;
	inv[0] = inv[1] = 1;
	for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i%INF;
	for (int i = 2; i < N; i++)
	{
		inv[i] = (INF - INF / i)*inv[INF%i] % INF;
	}
	for (int i = 2; i < N; i++) inv[i] = inv[i] * inv[i - 1] % INF;
}
LL C(int n, int m)
{
	return fact[n] * (inv[m] * inv[n - m] % INF) % INF;
}
bool check(int n, int a, int b)
{
	while (n)
	{
		if (n % 10 != a && n % 10 != b) return false;
		n /= 10;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, n;
	init();
	cin >> a >> b >> n;
	LL ans = 0;
	for (int i = 0; i <= n; i++)
	{
		if (check(i*a + (n - i)*b, a, b))
		{
			ans += C(n, i);
			if (ans >= INF) ans -= INF;
		}
	}
	cout << ans << endl;
	return 0;
}