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
char str[N];
int fail[N];
int ans[N];
vector<pair<int, int>> vp;
void getfail(int n)
{
	int j = 0;
	fail[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		while (j > 0 && str[j + 1] != str[i]) j = fail[j];
		if (str[j + 1] == str[i]) j++;
		fail[i] = j;
		ans[j]++;
	}
	int cur = n;
	ans[cur] = 1;
	for (int i = n; i > 0; i--) ans[fail[i]] += ans[i];
	while (cur)
	{
		vp.push_back({ cur,ans[cur] });
		cur = fail[cur];
	}
	reverse(vp.begin(), vp.end());
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	getfail(n);
	printf("%d\n", vp.size());
	for (auto &p : vp) printf("%d %d\n", p.first, p.second);
	return 0;
}