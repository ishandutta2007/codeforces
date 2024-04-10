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
vector<int> v1[N], v2[N];
LL solve(vector<int>& v)
{
	LL sum = 0;
	LL ans = 0;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		ans += 1LL * v[i] * i - sum;
		sum += v[i];
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x;
			scanf("%d", &x);
			v1[x].push_back(i);
			v2[x].push_back(j);
		}
	}
	LL ans = 0;
	for (int i = 1; i < N; i++)
		ans += solve(v1[i]) + solve(v2[i]);
	printf("%lld\n", ans);
	return 0;
}