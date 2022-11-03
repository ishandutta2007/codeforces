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
const int M = 1e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n;
	cin >> n;
	if (n <= 4)
	{
		cout << n * (n - 1) / 2 << endl;
		return 0;
	}
	LL cur = 1e11 - 1;
	while (cur > 10 && cur - min(cur - 1, n) > min(cur - 1, n)) cur /= 10;
	LL o = cur + 1;
	LL ans = 0;
	for (int i = 0; i < 11; i++)
	{
		LL l = cur - min(cur - 1, n);
		LL r = min(cur - 1, n);
		cur += o;
		if (l > r) continue;
		ans += (r - l + 1) / 2;
		
	}
	cout << ans << endl;
	return 0;
}