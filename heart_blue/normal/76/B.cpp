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
int a[N];
int b[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d%*d%*d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
	b[0] = -INF, b[m + 1] = INF;
	MEM(flag, -1);
	int ptr = 1;
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		while (ptr <= m && a[i] >= b[ptr]) ptr++;
		int lsum = a[i] - b[ptr - 1];
		int rsum = b[ptr] - a[i];
		if (lsum == rsum)
		{
			if (flag[ptr - 1] == -1 || flag[ptr - 1] == lsum) flag[ptr - 1] = lsum, tot++;
			else if (flag[ptr] == -1 || flag[ptr] == rsum) flag[ptr] = rsum, tot++;
		}
		else if (lsum < rsum)
		{
			if (flag[ptr - 1] == -1 || flag[ptr - 1] == lsum) tot++;
			flag[ptr - 1] = lsum;
		}
		else
		{
			if (flag[ptr] == -1 || flag[ptr] == rsum) tot++;
			flag[ptr] = rsum;
		}
		//cout << a[i] << ' ' << tot << endl;
	}
	printf("%d\n", n - tot);
	return 0;
}