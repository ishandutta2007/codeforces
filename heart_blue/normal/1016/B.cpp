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
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, q;
	cin >> n >> m >> q;
	if (n < m)
	{
		while (q--) puts("0");
		return 0;
	}
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i + m <= n; i++)
	{
		if (s1.substr(i, m) == s2)
		{
			flag[i + 1] = 1;
		}
	}
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		r = r - m + 1;
		int ans = 0;
		for (int i = l; i <= r; i++) ans += flag[i];
		printf("%d\n", ans);
	}
	return 0;
}