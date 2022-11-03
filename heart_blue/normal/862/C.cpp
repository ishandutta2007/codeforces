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
const int N = 3e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x;
	cin >> n >> x;
	if (n == 2 && x == 0)
	{
		cout << "NO" << endl;
		return 0;
	}
	if (n == 1)
	{
		cout << "YES" << endl;
		cout << x << endl;
		return 0;
	}
	if (n == 2)
	{
		cout << "YES" << endl;
		cout << x + 1 << ' ' << ((x + 1) ^ x) << endl;
		return 0;
	}
	cout << "YES" << endl;
	int sum = 0;
	for (int i = 1; i + 3 <= n; i++)
	{
		cout << i << ' ';
		sum ^= i;
	}
	int x7 = 1 << 17;
	int x8 = 1 << 18;
	cout << x7 << ' ' << x8 << ' ' << (x7^x8^sum^x) << endl;
	return 0;
}