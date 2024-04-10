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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int cnt[2][2];
		MEM(cnt, 0);
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			cnt[i & 1][x & 1]++;
		}
		if (cnt[0][0] * cnt[0][1] == 0 && cnt[1][0] * cnt[1][1] == 0)
			puts("Yes");
		else
			puts("No");
	}
	return 0;

}