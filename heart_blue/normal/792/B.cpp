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
#include <cassert>
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int flag[N];
int moveto(int cur, int k, int n)
{
	while (1)
	{
		if (cur > n) cur = 1;
		if (flag[cur])
		{
			cur++;
			continue;
		}
		if(k == 0) break;
		cur++;
		k--;
	}
	return cur;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	int cur = 1;
	int tot = n;
	MEM(flag, 0);
	while (k--)
	{
		int x;
		cin >> x;
		x %= tot--;
		cur = moveto(cur, x, n);
		flag[cur] = 1;
		cout << cur << ' ';
		cur = moveto(cur, 0, n);
	}
	return 0;
}