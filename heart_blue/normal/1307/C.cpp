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
const int N = 2e5 + 30;
LL cnt[200][200];
int tot[N];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%s", str + 1);
	n = strlen(str + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 'a'; j <= 'z'; j++)
		{
			cnt[str[i]][j] += tot[j];
		}
		tot[str[i]]++;
	}
	LL ans = 0;
	for (int i = 'a'; i <= 'z'; i++)
	{
		ans = max(ans, 1LL * tot[i]);
		for (int j = 'a'; j <= 'z'; j++)
		{
			ans = max(ans, cnt[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}