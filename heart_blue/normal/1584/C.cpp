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
const int N = 9e3 + 10;

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
		vector<int> a(n), b(n);
		for (auto& x : a) scanf("%d", &x);
		for (auto& x : b) scanf("%d", &x);
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int ok = 1;
		for (int i = 0; i < n; i++)
		{
			if (b[i] - a[i] >= 0 && b[i] - a[i] <= 1)
				;
			else
				ok = 0;
		}
		if (ok) puts("YES");
		else puts("NO");
	}
	return 0;
}