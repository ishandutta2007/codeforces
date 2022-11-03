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
const int N = 3e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, m;
	cin >> n >> m;
	LL ans = 0;
	int cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if ((i * i + j * j) % m == 0)
			{
				cnt++;
			}
		}
	}
	ans += (n / m) * (n / m) * cnt;
	cnt = 0;
	for (int i = 1; i <= n % m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if ((i * i + j * j) % m == 0)
			{
				cnt++;
			}
		}
	}
	ans += n / m * cnt * 2;
	for (int i = 1; i <= n % m; i++)
	{
		for (int j = 1; j <= n % m; j++)
		{
			if ((i * i + j * j) % m == 0)
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}