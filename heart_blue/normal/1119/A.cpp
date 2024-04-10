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
int L[N], R[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int l = INF, r = -INF;
	MEM(L, 0x3f);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		L[x] = min(L[x], i);
		R[x] = i;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (R[i] == 0) continue;
		if (l == INF)
		{
			l = L[i], r = R[i];
			continue;
		}
		ans = max({ ans,abs(R[i] - l),abs(L[i] - r) });
		l = min(l, L[i]);
		r = max(r, R[i]);
	}
	cout << ans << endl;
	return 0;
}