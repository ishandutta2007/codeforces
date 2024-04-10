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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 9;
const int N = 2e3 + 10;
int cnt[N];
int tot[N];
int a[20][20];
void init()
{
	for (int i = 0; i < (1 << 7); i++)
		cnt[i] = cnt[i >> 1] + (i & 1);
	for (int i = 0; i < (1 << 7); i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (i >> j & 1)
			{
				for (int k = 0; k < 7; k++)
				{
					if (i >> k & 1)
					{
						tot[i] += a[j][k];
					}
				}
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<string, int> ms;
	ms["Anka"] = 0;
	ms["Chapay"] = 1;
	ms["Cleo"] = 2;
	ms["Troll"] = 3;
	ms["Dracul"] = 4;
	ms["Snowy"] = 5;
	ms["Hexadecimal"] = 6;
	int n;
	cin >> n;
	while (n--)
	{
		string s1, op, s2;
		cin >> s1 >> op >> s2;
		a[ms[s1]][ms[s2]] = 1;
	}
	init();
	int a, b, c;
	cin >> a >> b >> c;
	int mask = (1 << 7) - 1;
	pair<int, int> ans = { int(2e9),0 };
	for (int i = 1; i <= mask; i++)
	{
		for (int j = 1; j <= mask; j++)
		{
			if (i&j) continue;
			int k = mask ^ (i | j);
			if (k == 0) continue;
			int x = a / cnt[i];
			int y = b / cnt[j];
			int z = c / cnt[k];
			ans = min(ans, { max({x,y,z}) - min({ x,y,z }),-(tot[i] + tot[j] + tot[k]) });
		}
	}
	printf("%d %d\n", ans.first, -ans.second);
	return 0;
}