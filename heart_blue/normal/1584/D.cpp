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
LL ask(int l, int r)
{
	cout << "? " << l << ' ' << r << endl;
	LL ret;
	cin >> ret;
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		LL tot = ask(1, n);
		int i = 1, j = 1, k = 1;
		int l = 1, r = n;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (ask(1, mid) == 0) i = mid, l = mid + 1;
			else r = mid - 1;
		}
		LL rest = ask(i + 1, n);
		j = i + (tot - rest) + 1;
		LL len1 = j - i;
		LL sum = tot - len1 * (len1 - 1) / 2;
		LL len2 = sqrt(sum * 2) + 1;
		k = j + len2 - 1;
		cout << "! " << i << ' ' << j << ' ' << k << ' ' << endl;
	}
	return 0;
}