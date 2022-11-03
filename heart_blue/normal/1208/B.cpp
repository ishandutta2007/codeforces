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
const int N = 2e3 + 10;
map<int, int> mc;
void add(int x)
{
	mc[x]++;
}
void del(int x)
{
	mc[x]--;
	if (mc[x] == 0)
		mc.erase(x);
}
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	map<int, int> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		m[a[i]]++;
	}
	if (m.size() == n)
		puts("0"), exit(0);
	int ans = INF;
	for (int i = 1; i <= n; i++)
	{
		mc = m;
		for (int j = i; j <= n; j++)
		{
			del(a[j]);
			if (mc.size() == i - 1 + n - j)
			{
				ans = min(j - i + 1, ans);
			}
		}
	}
	cout << ans << endl;
	return 0;
}