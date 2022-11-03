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
const int N = 1e5 + 10;
const int M = 333;
int L[N];
int R[N];
int LM[N];
int RM[N];
void build(int x)
{
	L[R[x]] = x;
	R[L[x]] = x;
	int key = x;
	int cnt = M;
	while (cnt--)
	{
		key = R[key];
	}
	for (int i = 0; i < M + 10; i++)
	{
		RM[x] = key;
		LM[key] = x;
		x = L[x];
		key = L[key];
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &R[i]);
		L[R[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		build(i);
	while (q--)
	{
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1)
		{
			swap(R[x], R[y]);
			L[R[x]] = x;
			L[R[y]] = y;
			build(x);
			build(y);
		}
		else
		{
			while (y >= M) y -= M, x = RM[x];
			while (y > 0) y--, x = R[x];
			printf("%d\n", x);
		}
	}
	return 0;
}