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
const int N = 2e5 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int flag1 = 0, flag2 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
		if (a[i] != b[i])
		{
			flag1 = 1;
		}
		if (i > 0 && a[i] > a[i - 1])
		{
			flag2 = 1;
		}
	}
	if (flag1) puts("rated");
	else if (flag2) puts("unrated");
	else puts("maybe");

	return 0;
}