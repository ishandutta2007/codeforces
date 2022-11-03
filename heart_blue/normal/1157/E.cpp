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
map<int, int> mc;
set<int> s;
int a[N];
void add(int x)
{
	s.insert(x);
	mc[x]++;
}
int getans(int x)
{
	auto iter = s.lower_bound(x);
	if (iter == s.end()) iter = s.begin();
	return *iter;
}
void del(int x)
{
	if (mc[x]-- == 1)
	{
		mc.erase(x);
		s.erase(x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		add(x);
	}
	for (int i = 1; i <= n; i++)
	{
		int x = a[i];
		int val = getans((n - x) % n);
		cout << (x + val) % n << ' ';
		del(val);
	}
	return 0;
}