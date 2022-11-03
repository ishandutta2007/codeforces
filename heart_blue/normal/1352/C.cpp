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
const int N = 1e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, k;
		cin >> n >> k;
		int l = 0, r = 2 * INF;
		int ans = 0;
		while (l <= r)
		{
			int mid = (1LL+l + r) / 2;
			LL tot = mid / n * (n - 1);
			tot += mid % n;
			if (tot >= k) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}