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
const int N = 1e6 + 10;
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	int a[2] = { 0,1 };
	while (q--)
	{
		int op;
		scanf("%d", &op);
		int x;
		if (op == 1)
		{
			scanf("%d", &x);
			if (abs(x) == n) x = 0;
			for (int i = 0; i < 2; i++)
			{
				a[i] += x;
				if (a[i] >= n) a[i] -= n;
				if (a[i] < 0) a[i] += n;
			}
		}
		else
		{
			for (int i = 0; i < 2; i++)
			{
				a[i] ^= 1;
			}
		}
	}
	a[1]--;
	if (a[1] < 0) a[1] += n;
	for (int i = 0; i < n; i++)
	{
		ans[(i + a[i & 1]) % n] = i + 1;
	}
	for (int i = 0; i < n; i++) printf("%d ", ans[i]);
	return 0;
}