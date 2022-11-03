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
const int N = 5e3 + 10;
LL fact[N];
LL powmod(LL a, LL b, LL mod = INF)
{
	if (b <= 0) return 1;
	LL ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % INF;
		b >>= 1;
		a = a*a%INF;
	}
	return ret;
}
void init()
{
	fact[0] = 1;
	for (int i = 1; i < N; i++)
	{
		fact[i] = i*fact[i - 1] % INF;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n, m;
	cin >> n >> m;
	LL ans = fact[n - m];
	vector<int> v(m);
	for (auto &x : v) cin >> x;
	sort(v.begin(), v.end());
	for (int i = 1; i < m; i++)
	{
		ans = ans * powmod(2, v[i] - v[i - 1] - 2) % INF;
		ans = ans * powmod(fact[v[i] - v[i - 1] - 1], INF - 2) % INF;
	}
	ans = ans * powmod(fact[v.front() - 1], INF - 2) % INF;
	ans = ans * powmod(fact[n - v.back()], INF - 2) % INF;
	cout << ans << endl;
	return 0;
}