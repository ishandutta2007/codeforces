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
LL a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = n; i > n / 2; i--) cin >> a[i];
	for (int i = n - 1; i > n / 2; i--)
	{
		int l = n - i + 1;
		int r = i;
		if (a[r] > a[r + 1])
		{
			a[l] += a[r] - a[r + 1];
			a[r] = a[r + 1];
		}
		if (a[l] < a[l - 1])
		{
			a[r] -= a[l - 1] - a[l];
			a[l] = a[l - 1];
		}
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
	return 0;
}