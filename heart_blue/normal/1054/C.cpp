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
const int N = 1e5 + 10;
int l[N];
int r[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> l[i];
	for (int i = 1; i <= n; i++) cin >> r[i];
	for (int i = 1; i <= n; i++)
	{
		a[i] = n - l[i] - r[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int cnt1 = 0;
		int cnt2 = 0;
		for (int j = 1; j <= n; j++)
		{
			if (a[j] <= a[i]) continue;
			if (j < i) cnt1++;
			if (j > i) cnt2++;
		}
		if (cnt1 != l[i]) puts("NO"), exit(0);
		if (cnt2 != r[i]) puts("NO"), exit(0);
	}
	puts("YES");
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
}