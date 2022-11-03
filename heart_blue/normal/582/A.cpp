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
const int N = 1e5 + 10;
int a[N];
map<int, int> m;
void del(int x, int o)
{
	m[x] -= o;
	if (m[x] == 0) m.erase(x);
}
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int tot = n*n;
	for (int i = 0; i < tot; i++)
	{
		int x;
		cin >> x;
		m[x]++;
	}
	for (int i = 0; i < n; i++)
	{
		int x = m.rbegin()->first;
		a[i] = x;
		del(x, 1);
		for (int j = 0; j < i; j++)
		{
			int g = gcd(a[i], a[j]);
			del(g, 2);
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	return 0;
}