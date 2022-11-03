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
const int N = 2e6 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, h, k;
	cin >> n >> h >> k;
	LL ans = 0;
	LL cur = 0;
	while (n--)
	{
		int x;
		cin >> x;
		int o = 1;
		if (cur + x > h)
		{
			int o = (cur + x - h - 1) / k + 1;
			cur -= o*k;
			if (cur < 0) cur = 0;
			ans += o;
		}
		cur += x;
	}
	ans += (cur - 1) / k + 1;
	cout << ans << endl;
	return 0;
}