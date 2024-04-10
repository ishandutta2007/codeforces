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
int v[N];
LL sum(LL x)
{
	return (x + 1)*(x + 2) / 2;
}
LL solve(int a, int b, int c, int l)
{
	LL ans = 0;
	for (int i = a; i <= a + l; i++)
	{
		if (i < b + c) continue;
		int r = a + l - i;
		ans += sum(min(r, i - b - c));
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, c, l;
	cin >> a >> b >> c >> l;
	LL ans = 0;
	for (int i = 0; i <= l; i++)
	{
		ans += sum(i);
	}
	ans -= solve(a, b, c, l) + solve(b, a, c, l) + solve(c, a, b, l);
	cout << ans << endl;
	return 0;
}