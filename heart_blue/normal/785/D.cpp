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
LL fact[N];
LL rfact[N];
void init()
{
	fact[0] = fact[1] = 1;
	rfact[0] = rfact[1] = 1;
	for (int i = 2; i < N; i++) fact[i] = fact[i - 1] * i % INF;
	for (int i = 2; i < N; i++) rfact[i] = (INF - INF / i)*rfact[INF%i] % INF;
	for (int i = 2; i < N; i++) rfact[i] = rfact[i] * rfact[i - 1] % INF;
}
LL solve(LL n, LL m)
{
	if (n < m) return 0;
	return fact[n] * rfact[m] % INF*rfact[n - m] % INF;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	string str;
	cin >> str;
	int r = 0;
	int l = 0;
	for (auto &c : str) r += c == ')';
	LL ans = 0;
	for (auto &c : str)
	{
		if (c == ')') r--;
		else
		{
			ans += solve(l + r, l + 1);
			l++;
		}
	}
	cout << ans % INF << endl;
	return 0;
}