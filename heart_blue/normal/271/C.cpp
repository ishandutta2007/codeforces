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
void getans(int a[], int x, int y)
{
	int b[] = { x,x, y, x,y,y };
	memcpy(a, b, sizeof(int) * 6);
}
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	if (k * 3 > n)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) a[i] = 1;
	int o = 0;
	for (int i = 1; i + 1 <= k; i += 2)
	{
		getans(a + o, i, i + 1);
		o += 6;
	}
	if (k & 1)
	{
		a[n - 1] = a[n - 2] = a[n - 3] = k;
		swap(a[0], a[n - 1]);
	}
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	return 0;
}