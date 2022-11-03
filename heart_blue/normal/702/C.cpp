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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<LL> v1(n+2), v2(m+2);
	for (int i = 1; i <= n; i++) cin >> v1[i];
	for (int i = 1; i <= m; i++) cin >> v2[i];
	v1[0] = v2[0] = -INF*INF;
	v1[n + 1] = v2[m + 1] = INF*INF;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	n = v1.size();
	m = v2.size();
	int r = 0;
	int ans = 0;
	for(auto &x : v1)
	{
		while (r < m - 1)
		{
			if (v2[r] <= x && x <= v2[r + 1]) break;
			r++;
		}
		int tmp = min(abs(x - v2[r]), abs(x - v2[r + 1]));
		ans = max(tmp, ans);
	}
	cout << ans << endl;

	
	return 0;
}