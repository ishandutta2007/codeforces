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
const int N = 2e2 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	a[0] = 0;
	a[n + 1] = 1001;
	int ans = 0;
	int cnt = 0;
	int tot = 0;
	for (int i = 1; i <= n + 1; i++)
	{
		if (i <= n) cin >> a[i];
		if (a[i] - a[i - 1] == 1) tot += (cnt++ > 0);
		else cnt = 0, tot = 0;
		ans = max(ans, tot);
	}
	cout << ans << endl;
	return 0;
}