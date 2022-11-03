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
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
pair<LL, int> check(int a, int b, int k)
{
	k = (k - a % k) % k;
	return make_pair(1LL * (a + k) * (b + k) / gcd(a + k, b + k), k);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);
	pair<LL, int> ans = make_pair(1LL * a * b / gcd(a, b), 0);
	if (a != b)
	{
		int o = b - a;
		for (int i = 1; i * i <= o; i++)
		{
			if (o % i) continue;
			ans = min(ans, check(a, b, i));
			ans = min(ans, check(a, b, o / i));
		}
	}
	cout << ans.second << endl;
	return 0;
}