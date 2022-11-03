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
const int N = 1e5 + 10;
LL a[N];
int l[N];
int r[N];
LL d[N];
LL cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	MEM(cnt, 0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> l[i] >> r[i] >> d[i];
	while (k--)
	{
		int x, y;
		cin >> x >> y;
		cnt[x]++;
		cnt[y + 1]--;
	}
	for (int i = 1; i <= m; i++)
	{
		cnt[i] += cnt[i - 1];
		d[i] *= cnt[i];
	}
	MEM(cnt, 0);
	for (int i = 1; i <= m; i++)
	{
		cnt[l[i]] += d[i];
		cnt[r[i] + 1] -= d[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cnt[i] += cnt[i - 1];
		cout << a[i] + cnt[i] << ' ';
	}
	return 0;
}