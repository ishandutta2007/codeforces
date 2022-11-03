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
int sum[N][26];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	for (int i = 1; i <= n; i++)
	{
		memcpy(sum[i], sum[i - 1], sizeof(sum[i]));
		sum[i][str[i] - 'a']++;
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		if (l == r || str[l] != str[r])
		{
			puts("Yes");
			continue;
		}
		int tot = 0;
		for (int i = 0; i < 26; i++)
			tot += sum[r][i] - sum[l - 1][i] > 0;
		if (tot >= 3) puts("Yes");
		else puts("No");

	}
	return 0;
}