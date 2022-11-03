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
int sz[N];
int ans[N];
int cnt[3][6];
vector<int> v[N];
int A[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int a, b;
	cin >> n >> a >> b;
	if (a == b)
	{
		while (a--) printf("1 ");
		while (b--) printf("2 ");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v[x].push_back(i);
		A[i] = x;
	}
	int o = 1;
	int tot;
	if (a > b) o = 1, tot = a;
	else o = 2, tot = b;
	for (int i = 1; i <= 5; i++)
		cnt[3 - o][i] = v[i].size();
	for (int i = 1; i <= 5; i++)
	{
		for (auto& x : v[i])
		{
			if (tot == 0) break;
			cnt[o][i]++;
			cnt[3 - o][i]--;
			tot--;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (cnt[1][A[i]] > 0)
		{
			cnt[1][A[i]]--;
			printf("1 ");
		}
		else
		{
			printf("2 ");
		}
	}
	return 0;
}