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
double rsum[N];
double lsum[N];
int flag[N];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", str+1);
	int n = strlen(str + 1);
	for (int i = 1; i <= n; i++)
	{
		lsum[i] = 1.0 / i + lsum[i - 1];
	}
	for (int i = n; i > 0; i--)
	{
		rsum[i] = (n - i + 1)*1.0 / i + rsum[i + 1];
	}
	string o = "AEIOUY";
	for (auto &c : o) flag[c] = 1;
	double ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (flag[str[i]] == 0) continue;
		int l = i;
		int r = n - i + 1;
		if (l > r) swap(l, r);
		ans += l;
		ans += (lsum[r] - lsum[l]) * l;
		ans += rsum[n - min(l, r) + 2];
	}
	printf("%.15f\n", ans);
	return 0;
}