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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n = 14;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i + n] = a[i];
	}
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		LL sum = 0;
		int x = a[i] / n;
		if (x % 2 == 0) sum += x;
		int r = a[i] % n;
		for (int j = 1; j < n; j++)
		{
			int o = a[i + j] + x + (j <= r);
			if (o % 2 == 0) sum += o;
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}