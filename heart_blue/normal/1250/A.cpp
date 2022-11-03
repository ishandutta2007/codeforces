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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int sz[N];
int maxv[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int mx = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> sz[i];
		for (int j = sz[i]; j > 0; j--)
		{
			int x;
			cin >> x;
			maxv[i] = max(maxv[i], x);
			mx = max(x, mx);
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
		ans += 1LL * sz[i] * (mx - maxv[i]);
	cout << ans << endl;
	return 0;
}