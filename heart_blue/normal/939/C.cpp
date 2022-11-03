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
const int N = 3e5 + 10;
LL a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i + n] = a[i];
	}
	for (int i = 1; i <= n*2; i++) a[i] += a[i - 1];
	int x, y;
	cin >> x >> y;
	int o = y - x;
	pair<LL, int> ans;
	for (int i = 0; i < n; i++)
	{
		int cur = x - i;
		while (cur <= 0) cur += n;
		ans = max(ans, { a[i + o] - a[i],-cur });
	}
	cout << -ans.second << endl;
	return 0;
}