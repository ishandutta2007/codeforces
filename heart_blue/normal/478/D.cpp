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
const int N = 2e3 + 10;
const int M = 2e5 + 10;
int m[2][M];
int sum[N];
int main()
{
	//freopen("B-large.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int r, g;
	cin >> r >> g;
	MEM(m[0], -1);
	m[0][0] = 1;
	int sz[2];
	sz[0] = 1;
	sz[1] = 0;
	for (int i = 0; i < N; i++)
	{
		sum[i] = i*(i + 1) / 2;
	}
	int key = 0;
	for (int i = 0; i < N; i++)
	{
		//cout << i << endl;
		int o = i & 1;
		int *mc = m[o];
		int *mn = m[o^1];
		if (sz[o] == 0)
		{
			key = i - 1;
			break;
		}
		memset(mn, -1, sizeof(int)*M);
		sz[o ^ 1] = 0;
		for (int j = 0; j < M; j++)
		{
			if (mc[j] == -1) continue;
			if (r - j >= i + 1)
			{
				int t = j + i + 1;
				auto &p = mn[t];
				if (p == -1) p = 0, sz[o ^ 1]++;
				p += mc[j];
				if (p >= INF) p -= INF;
			}
			if (g - sum[i] + j >= i + 1)
			{
				int t = j;
				auto &p = mn[t];
				if (p == -1) p = 0, sz[o ^ 1]++;
				p += mc[j];
				if (p >= INF) p -= INF;
			}
		}
	}
	int ans = 0;
	for (auto it : m[key&1])
	{
		if (it == -1) continue;
		ans += it;
		if (ans >= INF) ans -= INF;
	}
	cout << ans << endl;
	return 0;
}