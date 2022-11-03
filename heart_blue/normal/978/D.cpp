#pragma comment(linker, "/STACK:102400000,102400000") 
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
LL a[N];
LL b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	if (n <= 2)
	{
		puts("0");
		return 0;
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = INF;
	for (int o1 = -1; o1 <= 1; o1++)
	{
		for (int o2 = -1; o2 <= 1; o2++)
		{
			memcpy(b, a, sizeof(b));
			b[1] = a[1] + o1;
			b[2] = a[2] + o2;
			int tot = 0;
			if (o1 != 0) tot++;
			if (o2 != 0) tot++;
			LL d = b[2] - b[1];
			for (int i = 3; i <= n; i++)
			{
				if (abs(b[i] - b[i - 1] - d) > 1)
				{
					tot = INF;
					break;
				}
				if (b[i] != b[i - 1] + d)
				{
					b[i] = b[i - 1] + d;
					tot++;
				}
			}
			ans = min(ans, tot);
		}
	}
	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}