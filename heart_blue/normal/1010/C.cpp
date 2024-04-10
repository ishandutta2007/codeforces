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
	return m == 0 ? n : gcd(m, n%m);
}
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	int g = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		g = gcd(x%k, g);
	}
	for (int i = 1; i <= k; i++)
	{
		flag[1LL * i*g%k] = 1;
	}
	vector<int> v;
	for (int i = 0; i < k; i++)
	{
		if (flag[i])
			v.push_back(i);
	}
	printf("%d\n", v.size());
	for (auto &x : v) printf("%d ", x);
	return 0;
}