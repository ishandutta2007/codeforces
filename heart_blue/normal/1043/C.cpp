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
const int N = 3e5 + 10;
int ans[N];
int flag[N];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%s", str + 1);
	n = strlen(str + 1);
	flag[n] = 1;
	for (int i = n; i >= 1; i--)
	{
		if (str[i] == 'a') flag[i - 1] = -1;
		else flag[i - 1] = 1;
	}
	int f = 1;
	f = flag[1];
	for (int i = 2; i <= n; i++)
	{
		if (f != flag[i]) ans[i] = 1, f = flag[i];
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}