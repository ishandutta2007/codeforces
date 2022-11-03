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
const int N = 1e6 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int l = 1, r = 2 * n;
	int cur = 1;
	while (cur < n)
	{
		if (cur & 1)
		{
			a[l] = cur;
			a[l + n - cur] = cur;
			l++;
		}
		else
		{
			a[r] = cur;
			a[r + cur - n] = cur;
			r--;
		}
		cur++;
	}
	for (int i = 1; i <= 2 * n; i++)
	{
		if (a[i] == 0) a[i] = n;
		printf("%d ", a[i]);
	}
	return 0;
}