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
const int N = 3e3 + 10;
int s[N];
LL c[N];
LL minv1[N];
LL minv2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int j = 1; j <= n; j++) cin >> c[j];
	for (int i = 1; i <= n; i++) minv1[i] = minv2[i] = INF;
	LL ans = INF;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (i < j && s[i] < s[j])
			{
				minv1[j] = min(minv1[j], c[i]);
			}
			if (i > j && s[i] > s[j])
			{
				minv2[j] = min(minv2[j], c[i]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		ans = min(ans, c[i] + minv1[i] + minv2[i]);
	}
	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}