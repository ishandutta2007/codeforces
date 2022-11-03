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
const int N = 1e6 + 10;
int vis[N];
int tot[N];
int d[N][26];
LL gcd(LL n, LL m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, m;
	cin >> n >> m;
	string s1, s2;
	cin >> s1 >> s2;
	LL l1 = s1.length(), l2 = s2.length();
	LL ans = 0;
	MEM(vis, -1);
	LL g = gcd(l1, l2);
	LL lcm = l1 / g * l2;
	for (int i = 0; i < l1; i++)
	{
		int o = i % l2;
		if (vis[o] == -1)
		{
			int cur = o;
			while (vis[cur] == -1)
			{
				tot[i]++;
				d[i][s2[cur] - 26]++;
				vis[cur] = i;
				cur = (cur + l1) % l2;
			}
		}
		ans += (n*l1 / lcm)*(tot[vis[o]] - d[vis[o]][s1[i] - 26]);
	}
	cout << ans << endl;
	return 0;
}