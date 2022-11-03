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
pair<LL,int> a[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].first;
	for (int i = 1; i <= n; i++) cin >> a[i].second;
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++)
	{
		if (a[i].first == a[i + 1].first)
			flag[i] = flag[i + 1] = 1;
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (!flag[j]) continue;
			if ((a[i].first & a[j].first) == a[i].first)
			{
				ans += a[i].second;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}