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
int cur[N];
vector<int> v[N];
void init()
{
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N; j += i)
		{
			v[j].push_back(i);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	cin >> n;
	MEM(cur, 0);
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		int ans = 0;
		for (auto &d : v[x])
		{
			if (cur[d] < i - y) ans++;
			cur[d] = i;
		}
		printf("%d\n", ans);
	}
	return 0;
}