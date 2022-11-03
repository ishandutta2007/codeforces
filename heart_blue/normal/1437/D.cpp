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
int sz[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i <= n; i++) sz[i] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		int cur = 0;
		sz[0] = 1;
		int ptr = 2;
		while (ptr <= n)
		{
			int i = ptr + 1;
			while (i <= n && a[i] > a[i - 1]) i++;
			while (sz[cur] == 0) cur++;
			sz[cur]--;
			sz[cur + 1] += i - ptr;
			ptr = i;
		}
		printf("%d\n", cur + 1);
	}
	return 0;
}