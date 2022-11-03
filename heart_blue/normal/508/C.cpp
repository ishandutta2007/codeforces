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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int w[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int m, t, r;
	cin >> m >> t >> r;
	if (t < r)
	{
		puts("-1");
		return 0;
	}
	for (int i = 0; i < m; i++) cin >> w[i];
	sort(w, w + m);
	int o = t - w[0];
	for (int i = 0; i < m; i++) w[i] += max(0, o);
	MEM(flag, 0);
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= t; j++) cnt += flag[w[i] - j];
		for (int j = 1; j <= t; j++)
		{
			if (cnt >= r) break;
			if (flag[w[i] - j] == 0) flag[w[i] - j] = 1, cnt++, ans++;
		}
	}
	cout << ans << endl;
	return 0;
}