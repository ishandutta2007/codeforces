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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a[N];
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[0] = a[n + 1] = 0;
	for (int i = 1; i <= n; i++) a[i] = min(a[i], a[i - 1] + 1);
	for (int i = n; i > 0; i--) a[i] = min(a[i], a[i + 1] + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, a[i]);
	cout << ans << endl;
	return 0;
}