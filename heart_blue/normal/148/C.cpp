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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b;
	cin >> n >> a >> b;
	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	if (b == 0)
	{
		if (a + 2 > n)
		{
			cout << -1 << endl;
			return 0;
		}
		cout << "2 1";
		for (int i = 1; i <= a; i++) cout << ' ' << i + 2;
		int o = n - a - 2;
		while (o--) cout << ' ' << 1;
		return 0;
	}
	for (int i = 1; i <= b + 1; i++) cout << (1 << (i - 1)) << ' ';
	int cur = 1 << b;
	for (int i = 1; i <= a; i++) cout << cur + i << ' ';
	int r = n - a - b - 1;
	while (r--) cout << 1 << ' ';
	return 0;
}