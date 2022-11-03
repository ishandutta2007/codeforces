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
const int N = 2e5 + 10;
int row[N];
int col[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		row[x] = 1;
		col[y] = 1;
	}
	int ans = 0;
	for (int i = 2; i < n; i++)
	{
		if (row[i] == 0 && col[i] == 0)
		{
			if (i * 2 - 1 == n) ans++;
			else ans += 2;
		}
		else if (row[i] == 0 || col[i] == 0)
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}