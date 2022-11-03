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
const int N = 1e3 + 10;
int c[N];
int d[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, l, r;
	cin >> n >> m >> l >> r;
	MEM(flag, 0);
	int maxv = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		maxv = b;
		for (int j = a; j <= b; j++)
		{
			flag[j] = 1;
		}
	}
	for (int i = 0; i < m; i++) cin >> c[i] >> d[i];
	int ans = 0;
	for (int i = l; i <= r; i++)
	{
		int sum = 0;
		for (int j = 0; j < m; j++)
		{
			for (int k = c[j]; k <= d[j]; k++)
			{
				if (i + k > maxv) break;
				sum += flag[i + k];
			}
		}
		if (sum > 0) ans++;
	}
	cout << ans << endl;
	return 0;
}