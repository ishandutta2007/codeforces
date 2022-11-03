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
const int N = 1e5 + 10;
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
map<pair<int, int>, int> mc;
void add(int a, int b)
{
	if (a < 0) a = -a, b = -b;
	if (a == 0) b = 1;
	int g = gcd(abs(a), abs(b));
	a /= g;
	b /= g;
	mc[{a, b}] = 1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	while (n--)
	{
		int k, b;
		cin >> k >> b;
		if (k == 0) continue;
		add(-b, k);
	}
	cout << mc.size() << endl;
	return 0;
}