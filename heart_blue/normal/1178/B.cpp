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
const int N = 1e6 + 10;
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%s", str + 1);
	n = strlen(str + 1);
	int tot = 0;
	for (int i = 1; i < n; i++)
	{
		if (str[i] == str[i + 1] && str[i] == 'v')
			tot++;
	}
	int sum = 0;
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (str[i] == str[i - 1] && str[i] == 'v')
		{
			sum++;
			tot--;
		}
		if (str[i] == 'o')
		{
			ans += 1LL * sum * tot;
		}
	}
	cout << ans << endl;
	return 0;
}