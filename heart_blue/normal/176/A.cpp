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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;
int a[N][N];
int b[N][N];
int c[N][N];
int minv[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	MEM(minv, 0x3f);
	for (int i = 1; i <= n; i++)
	{
		scanf("%*s");
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j] >> b[i][j] >> c[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			vector<int> v;
			for (int o = 1; o <= m; o++)
			{
				for (int t = 0; t < c[i][o]; t++)
					v.push_back(max(0, b[j][o] - a[i][o]));
			}
			sort(v.rbegin(), v.rend());
			int sum = 0;
			for (int o = 0; o < k && o < v.size(); o++)
				sum += v[o];
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
	return 0;
}