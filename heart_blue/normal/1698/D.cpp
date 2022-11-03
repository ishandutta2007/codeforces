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
const int N = 3e5 + 10;
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
		int ans = n;
		int l = 1, r = n;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			cout << "? 1 " << mid << endl;
			int o = 0;
			for (int i = 1; i <= mid; i++)
			{
				int x;
				cin >> x;
				if (x > mid) o ^= 1;
			}
			if (mid % 2 == o) l = mid + 1;
			else r = mid - 1, ans = mid;
		}
		cout << "! " << ans << endl;
	}
	return 0;
}