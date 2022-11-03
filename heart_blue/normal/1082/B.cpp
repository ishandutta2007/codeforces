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
char str[N];
int tot[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	scanf("%s", str + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (str[i] == 'S') tot[i] = 0;
		else tot[i] = tot[i - 1] + 1;
		ans = max(ans, tot[i]);
	}
	int s = count(str + 1, str + n + 1, 'G');
	ans++;
	for (int i = n - 1; i >= 1; i--)
	{
		if (str[i] == 'G' && str[i + 1] == 'G')
			tot[i] = tot[i + 1];
	}
	for (int i = 2; i < n; i++)
	{
		if (tot[i] == 0 && tot[i - 1] && tot[i + 1])
			ans = max(ans, tot[i - 1] + tot[i + 1] + 1);
	}
	ans = min(ans, s);
	cout << ans << endl;
	return 0;
}