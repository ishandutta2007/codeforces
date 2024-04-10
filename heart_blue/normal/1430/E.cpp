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
vector<int> v[200];
char str[N];
int a[N];
class BIT
{
	int a[N];
public:
	void add(int x, int val = 1)
	{
		while (x < N)
		{
			a[x] += val;
			x += x & -x;
		}
	}
	int sum(int x)
	{
		int ret = 0;
		while (x)
		{
			ret += a[x];
			x -= x & -x;
		}
		return ret;
	}
} b;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	cin >> str + 1;
	for (int i = 1; i <= n; i++)
	{
		v[str[i] - 'a'].push_back(i);
	}
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			int x = v[i][j];
			int y = v[i][v[i].size() - j - 1];
			y = n - y + 1;
			a[x] = y;
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		b.add(a[i], 1);
		ans += i - b.sum(a[i]);
	}
	printf("%lld\n", ans);
	return 0;
}