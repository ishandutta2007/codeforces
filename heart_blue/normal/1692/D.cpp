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
#include <complex>
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
int vis[N];
int flag[N];
void init()
{
	for (int i = 0; i < 1440; i++)
	{
		int h = i / 60;
		int m = i % 60;
		char s[10];
		sprintf(s, "%02d:%02d", h, m);
		string s1 = s;
		string s2 = s1;
		reverse(s2.begin(), s2.end());
		if (s1 == s2)
			flag[i] = 1;

	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		MEM(vis, 0);
		int h, m, x;
		scanf("%d:%d", &h, &m);
		scanf("%d", &x);
		int cur = h * 60 + m;
		int ans = 0;
		while (vis[cur] == 0)
		{
			vis[cur] = 1;
			cur = (cur + x) % 1440;
			ans += flag[cur];
		}
		printf("%d\n", ans);
	}
	return 0;
}