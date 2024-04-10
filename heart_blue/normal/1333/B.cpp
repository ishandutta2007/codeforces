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
const int N = 2e5 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		int cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 1) cnt1++;
			if (a[i] == -1) cnt2++;
		}
		int flag = 1;
		for (int i = n; i >= 1; i--)
		{
			if (a[i] == 1) cnt1--;
			if (a[i] == -1) cnt2--;
			if (a[i] == b[i]) continue;
			if (a[i] < b[i] && cnt1 > 0) continue;
			if (a[i] > b[i] && cnt2 > 0) continue;
			flag = 0;
			break;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}