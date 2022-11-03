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
const int N = 128;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, p;
	string str;
	cin >> n >> p >> str;
	p--;
	if (p > n - p - 1) p = n - p - 1;
	int ans = 0;
	int l = 0, r = n - 1;
	int lb = INF, rb = -INF;
	while (l < r)
	{
		if (str[l] != str[r])
		{
			int o = abs(str[l] - str[r]);
			o = min(o, 26 - o);
			ans += o;
			lb = min(lb, l);
			rb = max(rb, l);
		}
		l++, r--;
	}
	if (ans == 0) cout << 0 << endl;
	else
	{
		ans += min(abs(p - lb), abs(p - rb)) + rb - lb;
		cout << ans << endl;
	}
	return 0;
}