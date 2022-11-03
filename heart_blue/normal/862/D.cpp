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
const int N = 1e3 + 10;
char str[N];
int n;
int ask()
{
	cout << "? " << str + 1 << endl;
	int ret;
	cin >> ret;
	return ret;
}
int ans[2];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	fill(str + 1, str + n + 1, '0');
	int cur0 = ask();
	str[1] = '1';
	int cur1 = ask();
	if (cur0 < cur1)
	{
		ans[0] = 1;
		int l = 2, r = n;
		int key = 2;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			fill(str + 2, str + n + 1, '0');
			fill(str + 2, str + mid + 1, '1');
			int cur2 = ask();
			if (cur2 - cur1 == mid - 1)
			{
				key = mid + 1;
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		ans[1] = key;
	}
	else //cur0 > cur1
	{
		ans[1] = 1;
		int l = 2, r = n;
		int key = 2;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			fill(str + 2, str + n + 1, '0');
			fill(str + 2, str + mid + 1, '1');
			int cur2 = ask();
			if (cur1 - cur2 == mid-1)
			{
				key = mid + 1;
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		ans[0] = key;
	}
	cout << "! " << ans[0] << ' ' << ans[1] << endl;
	return 0;
}