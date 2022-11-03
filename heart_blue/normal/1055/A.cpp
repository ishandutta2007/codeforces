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
const int N = 1e3 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, s;
	cin >> n >> s;
	if (s == 1) puts("YES"), exit(0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	if (a[1] == 0) puts("NO"), exit(0);
	if (a[s]) puts("YES"), exit(0);
	if (!b[s]) puts("NO"), exit(0);
	for (int i = s + 1; i <= n; i++)
	{
		if (a[i] && b[i]) puts("YES"), exit(0);
	}
	puts("NO");
	return 0;
}