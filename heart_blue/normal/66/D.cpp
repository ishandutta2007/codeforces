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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int p[] = { 5,7,11,13,17,19 };
	int n;
	cin >> n;
	if (n == 2)
	{
		puts("-1");
		return 0;
	}
	cout << 2 * 23 << endl;
	cout << 3 * 23 << endl;
	n -= 2;
	for (int i = 0; i < n; i++)
	{
		LL ans = 6;
		for (int j = 0; j < 6; j++)
		{
			if (i >> j & 1) ans *= p[j];
		}
		cout << ans << endl;
	}
	return 0;
}