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
int len(int l, int r)
{
	return r - l + 1;
}
int combine(int l, int r)
{
	return max(0, l - r + 1);
}
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		int L = len(max(1, i - k), min(n, i + k));
		if (x == 0)
		{
			ans[i] = L;
		}
		else
		{
			ans[i] = ans[x] + L - combine(min(x + k, n), max(1, i - k));
		}
		cout << ans[i] << ' ';
	}
	
	return 0;
}