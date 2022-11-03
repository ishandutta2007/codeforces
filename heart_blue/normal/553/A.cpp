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
const int N = 1e3 + 10;
LL A[N];
LL rA[N];
LL powmod(int a, int b, int mod = INF)
{
	LL ret = 1;
	LL o = a;
	while (b)
	{
		if (b & 1) ret = ret * o % mod;
		o = o*o%mod;
		b >>= 1;
	}
	return ret;
}
void init()
{
	A[0] = 1;
	for (int i = 1; i < N; i++) A[i] = A[i - 1] * i %INF;
	for (int i = 0; i < N; i++) rA[i] = powmod(A[i], INF - 2);
}
LL C(int n, int m)
{
	return A[n] * rA[m] % INF * rA[n - m] % INF;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	cin >> n;
	LL ans = 1;
	int sum = 0;
	while (n--)
	{
		int x;
		cin >> x;
		sum += x;
		ans = ans*C(sum - 1, x - 1) % INF;
	}
	cout << ans << endl;
	return 0;
}