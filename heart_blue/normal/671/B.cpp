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
const int N = 5e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	LL tot = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], tot += a[i];
	sort(a + 1, a + n + 1);
	int lmax = a[1], rmin = a[n];
	LL sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += a[i];
		if (i == n)
		{
			lmax = a[n];
			break;
		}
		LL r = 1LL * a[i] * i - sum;
		r = k - r;
		if (a[i] + r / i < a[i + 1])
		{
			lmax = a[i] + r / i;
			break;
		}
	}
	sum = 0;
	for (int i = n; i >= 1; i--)
	{
		sum += a[i];
		if (i == 1)
		{
			rmin = a[1];
			break;
		}
		LL r = sum - 1LL * a[i] * (n - i + 1);
		r = k - r;
		if (a[i] - r / (n - i + 1) > a[i - 1])
		{
			rmin = a[i] - r / (n - i + 1);
			break;
		}
	}
	if (lmax < rmin)
	{
		cout << rmin - lmax << endl;
		return 0;
	}
	LL avg = tot / n;
	if (tot % n) cout << 1 << endl;
	else cout << 0 << endl;
	return 0;
}