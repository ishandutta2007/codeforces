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
const int N = 1e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, p;
	cin >> n >> p;
	LL tot = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		tot += a[i];
	}
	LL ans = 0;
	LL sum = 0;
	for (int i = 1; i < n; i++)
	{
		sum += a[i];
		ans = max(ans, sum%p + (tot - sum) % p);
	}
	cout << ans << endl;
	return 0;
}