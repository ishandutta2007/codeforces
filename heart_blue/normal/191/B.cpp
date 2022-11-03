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
pair<int, int> a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	LL b;
	cin >> b;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	a[n].first = 0;
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	LL sum = 0;
	for (int i = 1; i < k; i++)
	{
		sum += a[i].first;
	}
	int ans = n;
	for (int i = 1; i <= n; i++)
	{
		if (sum + a[max(k, i)].first > b)
			ans = min(ans, a[i].second);
	}
	cout << ans << endl;
	return 0;
}