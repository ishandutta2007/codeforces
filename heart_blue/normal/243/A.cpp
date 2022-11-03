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
const int M = 1e7;
int nex[N][21];
int a[N];
int ans[M];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	MEM(ans, 0);
	cin >> n;
	a[n + 1] = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < 21; i++) nex[n + 1][i] = n + 1;
	for (int i = n; i > 0; i--)
	{
		for (int k = 0; k < 21; k++)
		{
			if (1 << k&a[i]) nex[i][k] = i;
			else nex[i][k] = nex[i + 1][k];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int sum = a[i];
		ans[sum] = 1;
		vector<pair<int, int>> vp;
		for (int k = 0; k < 21; k++)
		{
			vp.push_back({ nex[i][k],k });
		}
		sort(vp.begin(), vp.end());
		int pre = -1;
		for (auto &p : vp)
		{
			sum |= a[p.first];
			ans[sum] = 1;
		}
	}
	int tot = 0;
	for (int i = 0; i < M; i++)
	{
		tot += ans[i];
	}
	cout << tot << endl;
	return 0;
}