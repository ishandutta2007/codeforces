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
const int N = 2e2 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, c0, c1, h;
		scanf("%d%d%d%d", &n, &c0, &c1, &h);
		string str;
		cin >> str;
		int cnt0 = count(str.begin(), str.end(), '0');
		int cnt1 = n - cnt0;
		int ans = INF;
		for (int i = 0; i <= n; i++)
		{
			ans = min(ans, i * c0 + (n - i) * c1 + abs(i - cnt0) * h);
		}
		printf("%d\n", ans);
	}
	return 0;
}