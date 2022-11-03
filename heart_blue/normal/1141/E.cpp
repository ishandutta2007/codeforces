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
	LL h;
	int n;
	cin >> h >> n;
	LL sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	LL l = 0, r = sum >= 0 ? 0LL : (h / (-sum) + 1);
	LL ans = -1;
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		LL rest = h + mid * sum;
		int key = 0;
		for (int i = 1; i <= n; i++)
		{
			rest += a[i];
			if (rest <= 0)
			{
				key = i;
				break;
			}
		}
		if (key) r = mid - 1, ans = mid * n + key;
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}