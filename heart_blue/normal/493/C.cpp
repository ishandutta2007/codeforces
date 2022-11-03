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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	int x, y;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	cin >> m;
	for (int j = 0; j < m; j++)
	{
		cin >> b[j];
	}
	x = 2 * n;
	y = 2 * m;
	sort(a, a + n);
	reverse(a, a + n);
	sort(b, b + m);
	reverse(b, b + m);
	
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		while (p < m && b[p] >= a[i]) p++;
		int t1 = (i+1) * 3 + (n - i - 1) * 2;
		int t2 = p * 3 + (m - p) * 2;
		if (x - y <= t1 - t2) x = t1, y = t2;
	}
	cout << x << ':' << y << endl;
	return 0;
}