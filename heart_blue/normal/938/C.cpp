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
const int N = 5e3 + 10;
bool check(int x)
{
	for (int i = 2; i*i - 1 <= x; i++)
	{
		LL l = i, r = INF;
		while (l <= r)
		{
			LL mid = (l + r) / 2;
			LL tot = mid / i * (mid*i - mid / i) + mid % i*mid;
			if (tot > x) r = mid - 1;
			else if (tot < x) l = mid + 1;
			else
			{
				cout << mid << ' ' << i << endl;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			cout << 1 << ' ' << 1 << endl;
			continue;
		}
		if (!check(x)) cout << -1 << endl;
	}
	return 0;
}