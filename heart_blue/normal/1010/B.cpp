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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << 1 << endl;
		cin >> a[i];
		if (a[i] == 0)
		{
			exit(0);
		}
	}
	int l = 2, r = m;
	int o = 1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		cout << mid << endl;
		int flag;
		cin >> flag;
		flag *= -a[o++];
		if (o > n) o = 1;
		if (flag == 0)
		{
			exit(0);
		}
		if (flag == -1) l = mid + 1;
		else r = mid - 1;
	}
	return 0;
}