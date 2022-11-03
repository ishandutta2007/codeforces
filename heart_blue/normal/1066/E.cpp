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
const int N = 2e5 + 20;
const int MOD = 998244353;
int p2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	int len = max(a.length(), b.length());
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	a += string(len - a.length(), '0');
	b += string(len - b.length(), '0');
	int cnt = count(b.begin(), b.end(), '1');
	p2[0] = 1;
	for (int i = 1; i < N; i++)
	{
		p2[i] = p2[i - 1] * 2;
		if (p2[i] >= MOD) p2[i] -= MOD;
	}
	LL ans = 0;
	for (int i = 0; i < len; i++)
	{
		if (a[i] == '1')
		{
			ans += 1LL * p2[i] * cnt%MOD;
		}
		cnt -= b[i] - '0';
	}
	cout << ans % MOD << '\n';
	return 0;
}