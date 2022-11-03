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
const int N = 2e2 + 10;
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v[x].push_back(i - 1);
	}
	string ans(n, 'A');
	int o = 0;
	int key = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (v[i].empty()) continue;
		if (v[i].size() == 1)
		{
			ans[v[i].front()] = 'A' + o;
			o ^= 1;
		}
		if (v[i].size() > 2)
		{
			key = i;
		}
	}
	if (o)
	{
		if (key) ans[v[key].front()] = 'B';
		else puts("NO"), exit(0);
	}
	puts("YES");
	puts(ans.c_str());
	return 0;
}