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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3+ 10;
int deg[N];
int fa[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	MEM(deg, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> fa[i];
		if (fa[i] != -1) deg[fa[i]]++;
	}
	int ans = 0;
	while (1)
	{
		vector<int> v;
		for (int i = 1; i <= n; i++)
		{
			if (deg[i] == 0) v.push_back(i);
		}
		if (v.empty()) break;
		ans++;
		for (auto &x : v)
		{
			deg[x] = -1;
			if (fa[x] != -1) deg[fa[x]]--;
		}
	}
	cout << ans << endl;
	return 0;
}