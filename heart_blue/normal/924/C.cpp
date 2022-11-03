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
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	memcpy(b, a, sizeof(a));
	for (int i = 1; i <= n; i++) a[i]++;
	for (int i = 2; i <= n; i++)
	{
		a[i] = max(a[i], a[i - 1]);
	}
	for (int i = n - 1; i > 0; i--)
	{
		a[i] = max(a[i], a[i + 1] - 1);
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++) ans += a[i] - b[i] - 1;
	cout << ans << endl;
	return 0;
}