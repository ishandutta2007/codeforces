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
const int N = 2e5 + 10;
const int M = 450;
int a[N];
int b[N];
int block[M];
int fblock[M];
int fb[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int o = 1; o <= q; o++)
	{
		int op;
		int x, y, k;
		cin >> op;
		if (op == 1)
		{
			cin >> x >> y >> k;
			x--, y--;
			int l = y, r = y + k - 1;
			auto refrain = [&](int L, int R)
			{
				for (int i = L; i <= R; i++) b[i] = a[x + i - l];
				for (int i = L; i <= R; i++) fb[i] = o;
			};
			if (l / M == r / M)
			{
				refrain(l, r);
			}
			else
			{
				refrain(l, l / M*M + M - 1);
				refrain(r / M*M, r);
				int p = x + l / M*M + M - l;
				for (int i = l / M + 1; i < r / M; i++)
				{
					block[i] = p;
					fblock[i] = o;
					p += M;
				}
			}
		}
		else
		{
			cin >> x;
			x--;
			if (fblock[x / M] > fb[x])
			{
				printf("%d\n", a[block[x / M] + x%M]);
			}
			else
			{
				printf("%d\n", b[x]);
			}
		}
	}
	return 0;
}