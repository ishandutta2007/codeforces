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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e4 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> a[i];
	int cnt1 = 0, cnt4 = n, cnt2 = n*2;
	for (int i = 1; i <= m; i++)
	{
		while (a[i] >= 4 && cnt4 > 0) a[i] -= 4, cnt4--;
	}
	cnt2 += cnt4, cnt1 += cnt4;
	for (int i = 1; i <= m; i++)
	{
		while (a[i] >= 2 && cnt2 > 0) a[i] -= 2, cnt2--;
	}
	cnt1 += cnt2;
	for (int i = 1; i <= m; i++)
	{
		while (a[i] >= 1 && cnt1 > 0) a[i]--, cnt1--;
	}
	int flag = 1;
	for (int i = 1; i <= m; i++)
	{
		if (a[i]) flag = 0;
	}
	if (flag) puts("YES");
	else puts("NO");
	return 0;
}