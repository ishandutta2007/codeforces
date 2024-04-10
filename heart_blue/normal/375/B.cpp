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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
char str[N][N];
int len[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	MEM(len, 0);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", &str[i][1]);
		for (int j = 1; j <= m; j++)
		{
			if (str[i][j] == '1') len[i][j] = 1 + len[i][j - 1];
			else len[i][j] = 0;
		}
	}
	int ans = 0;
	for (int j = 1; j <= m; j++)
	{
		vector<int> v;
		for (int i = 1; i <= n; i++) v.push_back(len[i][j]);
		sort(v.rbegin(), v.rend());
		for (int i = 0; i < v.size(); i++)
		{
			ans = max(ans, (i + 1)*v[i]);
		}
	}
	cout << ans << endl;
	return 0;
}