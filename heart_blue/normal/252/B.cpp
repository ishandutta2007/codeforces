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
int a[N];
bool check1(vector<int> &v)
{
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i - 1] <= v[i]) continue;
		return false;
	}
	return true;
}
bool check2(vector<int> &v)
{
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i - 1] >= v[i]) continue;
		return false;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	if (n <= 2)
	{
		cout << -1 << endl;
		return 0;
	}
	vector<int> v(n);
	map<int, int> mc;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		mc[v[i]] = i;
	}
	if (mc.size() == 1)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) a[i] = i;
	for (auto &p : mc)
	{
		int o = 20;
		int x = p.second;
		while (o--)
		{
			random_shuffle(a, a + n);
			int y = a[0];
			if (v[x] == v[y]) continue;
			swap(v[x], v[y]);
			if (check1(v) || check2(v))
			{
				swap(v[x], v[y]);
				continue;
			}
			cout << x + 1 << ' ' << y + 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	
	return 0;
}