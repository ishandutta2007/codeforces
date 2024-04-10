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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int ask(int l, int r)
{
	if (l == r) return -1;
	if (l > r) swap(l, r);
	cout << "? " << l << ' ' << r << endl;
	int ret;
	cin >> ret;
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int key = ask(1, n);
	int l = 1, r = n;
	int ret = 0;
	while (r - l > 1)
	{
		int mid = (l + r) / 2;
		if (mid < key)
		{
			int x = ask(mid, max(key, r));
			if (x == key) ret = mid, l = mid + 1;
			else r = mid - 1;
		}
		else
		{
			int x = ask(min(key, l), mid);
			if (x == key) ret = mid, r = mid - 1;
			else l = mid + 1;
		}
	}
	if (l <= r)
	{
		if (r <= key)
		{
			if (ask(r, key) == key) ret = r;
			else if (ask(l, key) == key) ret = l;
		}
		else
		{
			if (ask(l, key) == key) ret = l;
			else if (ask(r, key) == key) ret = r;
		}
	}
	cout << "! " << ret << endl;
	return 0;
}