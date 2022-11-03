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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const int INF = 1e9 + 7;
const int N = 5e6 + 10;
int a[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int mask = (1 << 22) - 1;
	MEM(flag, -1);
	scanf("%d", &n);
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		flag[a[i]] = a[i];
		q.push(a[i]);
	}
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < 22; i++)
		{
			if (x >> i & 1) continue;
			if (flag[1 << i | x] >= 0) continue;
			flag[1 << i | x] = flag[x];
			q.push(1 << i | x);
		}
	}
	for (int i = 0; i < n; i++)
	{
		int ans = flag[mask^a[i]];
		printf("%d ", ans);
	}
	return 0;
}