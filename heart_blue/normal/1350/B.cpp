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
vector<int> v[N];
int a[N];
int dp[N];
void init()
{
	for (int i = 1; i < N; i++)
	{
		for (int j = i + i; j < N; j += i)
			v[j].push_back(i);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			dp[i] = 0;
			cin >> a[i];
			for (auto& d : v[i])
			{
				if (a[i] > a[d])
					dp[i] = max(dp[i], dp[d]);
			}
			ans = max(ans, ++dp[i]);
		}
		cout << ans << endl;
	}
	return 0;
}