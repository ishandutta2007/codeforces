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
const int N = 5e5 + 10;
int a[N];
string str;
LL solve(int n)
{
	LL tot = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'B') tot += a[i];
	}
	LL ret = tot;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'A') tot += a[i];
		else tot -= a[i];
		ret = max(ret, tot);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> str;
	LL ans1 = solve(n);
	reverse(a, a + n);
	reverse(str.begin(), str.end());
	LL ans2 = solve(n);
	cout << max(ans1, ans2) << endl;
	return 0;
}