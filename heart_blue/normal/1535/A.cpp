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
const int N = 5e1 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int a[5];
		for (int i = 1; i <= 4; i++)
		{
			scanf("%d", &a[i]);
		}
		int maxv1 = *max_element(a + 1, a + 5);
		int maxv2 = maxv1 ^ max(a[1], a[2]) ^ max(a[3], a[4]);
		sort(a + 1, a + 5);
		if (maxv2 == a[3]) puts("YES");
		else puts("NO");
	}
	return 0;
}