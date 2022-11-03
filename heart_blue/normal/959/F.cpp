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
vector<pair<int, int>> vp[N];
int ans[N];
int p2[N];
int a[N];
int b[20];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	p2[0] = 1;
	for (int i = 1; i < N; i++) p2[i] = p2[i - 1] * 2 % INF;
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= q; i++)
	{
		int l, x;
		cin >> l >> x;
		vp[l].push_back({ x,i });
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 19; j >= 0; j--)
		{
			if (a[i] >> j & 1)
			{
				if (b[j]) a[i] ^= b[j];
				else
				{
					b[j] = a[i];
					cnt++;
					break;
				}
			}
		}
		for (auto &p : vp[i])
		{
			int x, pos;
			tie(x, pos) = p;
			for (int j = 19; j >= 0; j--)
			{
				if (x >> j & 1) x ^= b[j];
			}
			if (x == 0) ans[pos] = p2[i - cnt];
			else ans[pos] = 0;
		}
	}
	for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
	return 0;
}