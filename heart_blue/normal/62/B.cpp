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
const int N = 2e5 + 10;
char str[N];
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 0; i < N; i++) v[i].push_back(-INF);
	int q, len;
	scanf("%d%d", &q, &len);
	scanf("%s", str + 1);
	for (int i = 1; i <= len; i++)
	{
		v[str[i]].push_back(i);
	}
	for (int i = 0; i < N; i++) v[i].push_back(INF);
	while (q--)
	{
		scanf("%s", str + 1);
		int m = strlen(str + 1);
		LL sum = 0;
		for (int i = 1; i <= m; i++)
		{
			if (v[str[i]].size() == 2)
			{
				sum += m;
				continue;
			}
			auto iter = upper_bound(v[str[i]].begin(), v[str[i]].end(), i);
			int r = *iter;
			iter--;
			int l = *iter;
			sum += min(i - l, r - i);
		}
		printf("%lld\n", sum);
	}
	return 0;
}