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
const int N = 1e5 + 10;
char a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	scanf("%s", a + 1);
	map<int, int> mc;
	mc[0] = 0;
	int ans = 0;
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == '1') tot++;
		else tot--;
		if (mc.count(tot)) ans = max(ans, i - mc[tot]);
		else mc[tot] = i;
	}
	cout << ans << endl;
	return 0;
}