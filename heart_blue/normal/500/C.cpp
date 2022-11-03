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
const int N = 1e3 + 10;
int w[N];
int flag[N];
int s[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	MEM(flag, 0);
	for (int i = 1; i <= n; i++) cin >> w[i];
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		cin >> s[i];
		for (int j = i - 1; j > 0; j--)
		{
			if (flag[s[j]] == i) continue;
			if (s[j] == s[i]) break;
			flag[s[j]] = i;
			ans += w[s[j]];
		}
	}
	cout << ans << endl;
	return 0;
}