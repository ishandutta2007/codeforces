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
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
fo\
r(int i = 1; i <= n; i++)
fo\
r(int j = 1; j <= n; j++)
	{
		cin >> a[i][j];
	}
fo\
r(int k = 1; k <= n; k++)
fo\
r(int i = 1; i <= n; i++)
fo\
r(int j = 1; j <= n; j++)
		a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	int ans = 0;
fo\
r(int i = 1; i <= n; i++)
fo\
r(int j = 1; j <= n; j++)
		ans = max(ans, a[i][j]);
	cout << ans << endl;
	return 0;
}