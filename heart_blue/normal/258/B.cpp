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
const int N = 4e5 + 10;
int d[20];
int dp[20][20];
int cnt[20];
LL v[20][10];
int key;
int dfs(int pos, int state, bool lead = true, bool limit = true)
{
	if (pos == -1)
	{
		return state == key ? 1 : 0;
	}
	if (!limit && !lead && dp[pos][state] != -1) return dp[pos][state];
	int up = limit? d[pos] : 9;
	int ret = 0;
	for (int i = 0; i <= up; i++)
	{
		ret += dfs(pos - 1, state + (i == 4 || i == 7), lead && i == 0, limit && i == d[pos]);
	}
	if (!limit && !lead) dp[pos][state] = ret;
	return ret;
}
void solve(int n, int k)
{
	key = k;
	int len = 0;
	while (n)
	{
		d[len++] = n % 10;
		n /= 10;
	}
	MEM(dp, -1);
	cnt[k] = dfs(len - 1, 0);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i <= 9; i++)
	{
		solve(n, i);
		if (i == 0) cnt[i]--;
		int x = cnt[i];
		v[i][0] = 1;
		for (int j = 1; j <= 7; j++)
		{
			v[i][j] = v[i][j - 1] * (x - j + 1) % INF;
		}
	}
	LL ans = 0;
	for (int a = 1; a <= 9; a++)
	{
		for (int b = 0; b < a; b++)
		{
			for (int c = 0; b + c < a; c++)
			{
				for (int d = 0; b + c + d < a; d++)
				{
					for (int e = 0; b + c + d + e < a; e++)
					{
						for (int f = 0; b + c + d + e + f < a; f++)
						{
							for (int g = 0; b + c + d + e + f + g < a; g++)
							{
								int tot[10];
								MEM(tot, 0);
								int ar[] = { a,b,c,d,e,f,g };
								for (int i = 0; i < 7; i++) tot[ar[i]]++;
								LL res = 1;
								for (int i = 0; i < 10; i++)
								{
									res = res * v[i][tot[i]] % INF;
								}
								ans += res;
							}
						}
					}
				}
			}
		}
	}
	printf("%lld\n", ans % INF);
	return 0;
}