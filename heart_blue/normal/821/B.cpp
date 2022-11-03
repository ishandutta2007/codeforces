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
LL sum(LL x)
{
	return x*(x + 1) / 2;
}
LL sum(int x, int y)
{
	return sum(x)*(y + 1) + sum(y)*(x + 1);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL ans = 0;
	int m, b;
	cin >> m >> b;
	for (int i = 0; i <= b*m; i++)
	{
		ans = max(ans, sum(i, (b*m - i) / m));
	}
	cout << ans << endl;
	return 0;
}