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
vector<int> v[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int cur = -1;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v[x].push_back(i);
	}
	int tot = 0;
	while (cur >= -1)
	{
		if (v[cur + 1].empty())
		{
			cur -= 3;
		}
		else
		{
			int x = v[cur + 1].back();
			v[cur + 1].pop_back();
			ans[++tot] = x;
			cur++;
		}
	}
	if (tot == n)
	{
		puts("Possible");
		for (int i = 1; i <= n; i++)
		{
			printf("%d ", ans[i]);
		}
	}
	else puts("Impossible");
	return 0;
}