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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL sum(LL x)
{
	return x * (x - 1) / 2;
}
LL solve(int x, int n)
{
	return n / x + x * sum(n / x);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<LL> v;
	int n;
	cin >> n;
	for (int i = 1; i*i <= n; i++)
	{
		if (n%i) continue;
		v.push_back(solve(i, n));
		if (i != n / i) v.push_back(solve(n / i, n));
	}
	sort(v.begin(), v.end());
	for (auto &x : v) cout << x << ' ';
	return 0;
}