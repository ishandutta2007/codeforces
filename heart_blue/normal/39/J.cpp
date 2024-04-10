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
char s1[N];
char s2[N];
int flag1[N];
int flag2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s%s", s1 + 1, s2 + 1);
	int n = strlen(s1 + 1);
	int m = n - 1;
	flag1[0] = 1, flag2[n + 1] = 1;
	for (int i = 1; i < n; i++)
	{
		if (s1[i] == s2[i]) flag1[i] = 1;
		else break;
	}
	for (int i = n; i > 1; i--)
	{
		if (s1[i] == s2[i - 1]) flag2[i] = 1;
		else break;
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		if (flag1[i - 1] && flag2[i + 1])
			ans.push_back(i);
	}
	printf("%d\n", ans.size());
	for (auto& x : ans) printf("%d ", x);
	return 0;
}