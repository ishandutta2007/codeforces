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
const int N = 1e6 + 10;
int a[N];
int cnt[N];
int total = 0;
void add(int x)
{
	if (cnt[x]++ == 0) total++;
}
void sub(int x)
{
	if (cnt[x]-- == 1) total--;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(cnt, 0);
	pair<int, int> ans = { 1,1 };
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int p = 1;
	for (int i = 1; i <= n; i++)
	{
		while (p <= n)
		{
			add(a[p]);
			if (total > k)
			{
				sub(a[p]);
				break;
			}
			p++;
		}
		ans = max(ans, { p - i,i });
		sub(a[i]);
	}
	cout << ans.second << ' ' << ans.second + ans.first - 1 << endl;
	return 0;
}