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
const int N = 1e3 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x;
	cin >> n >> x;
	MEM(a, 0);
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		cin >> l >> r;
		if (l > r) swap(l, r);
		a[l]++;
		a[r + 1]--;
	}
	int sum = 0;
	int ans = INF;
	for (int i = 0; i < N; i++)
	{
		sum += a[i];
		if (sum == n) ans = min(ans, abs(x - i));
	}
	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}