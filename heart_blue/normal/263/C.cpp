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
int a[N];
int flag[N];
int getrest(int x, int a1, int a2, int a3)
{
	int o[3] = { a1,a2,a3 };
	set<int> s(v[x].begin(), v[x].end());
	for (int i = 0; i < 3; i++)
	{
		auto iter = s.find(o[i]);
		if (iter == s.end()) return -1;
		s.erase(iter);
	}
	return *s.begin();

}
bool check(int n)
{
	MEM(flag, 0);
	for (int i = 4; i <= n; i++)
	{
		int x = getrest(a[i], a[i - 2], a[i - 1], a[i + 1]);
		if (x == -1) return false;
		a[i + 2] = x;
	}
	if (a[n + 1] != a[1]) return false;
	if (a[n + 2] != a[2]) return false;
	for (int i = 1; i <= n; i++) flag[a[i]] = 1;
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += flag[i];
	if (cnt != n) return false;
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= 2 * n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		if (v[i].size() != 4)
		{
			puts("-1");
			return 0;
		}
		sort(v[i].begin(), v[i].end());
	}
	vector<int> vv = v[1];
	do
	{
		a[1] = vv[0];
		a[2] = vv[1];
		a[3] = 1;
		a[4] = vv[2];
		a[5] = vv[3];
		if (check(n)) return 0;
	} while (next_permutation(vv.begin(), vv.end()));
	puts("-1");
	return 0;
}