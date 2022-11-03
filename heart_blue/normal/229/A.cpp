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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e4 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	string str;
	MEM(a, 0);
	for (int i = 0; i < n; i++)
	{
		MEM(b, 0x1f);
		cin >> str;
		int k = -1;
		for (int j = 0; j < m; j++)
		{
			if (str[j] == '1')
			{
				k = j;
				break;
			}
		}
		if (k == -1)
		{
			cout << -1 << endl;
			return 0;
		}
		int pre = 0;
		for (int j = 0; j < m; j++)
		{
			int o = (k + j) % m;
			if (str[o] == '1') pre = j;
			b[o] = min(b[o], j - pre);
		}
		pre = 0;
		for (int j = 0; j < m; j++)
		{
			int o = (k + m - j) % m;
			if (str[o] == '1') pre = j;
			b[o] = min(b[o], j - pre);
		}
		for (int j = 0; j < m; j++) a[j] += b[j];
	}
	int ans = INF;
	for (int i = 0; i < m; i++) ans = min(ans, a[i]);
	cout << ans << endl;
	return 0;
}