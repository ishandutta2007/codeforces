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
const int N = 2e6 + 10;
int a[N];
void init()
{
	for (int i = 2; i < N; i++)
	{
		if (a[i]) continue;
		for (int j = i + i; j < N; j += i) a[j] = 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	vector<int> v;
	cin >> n;
	int cnt = 0;
	while (n--)
	{
		int x;
		cin >> x;
		if (x == 1) cnt++;
		else v.push_back(x);
	}
	for (auto &x : v)
	{
		if (a[1 + x] == 0)
		{
			if (cnt >= 1)
			{
				cout << cnt + 1 << '\n';
				while (cnt--) cout << 1 << ' ';
				cout << x << endl;
				return 0;
			}
		}
	}
	if (cnt > 1)
	{
		cout << cnt << '\n';
		while (cnt--) cout << 1 << ' ';
		return 0;
	}
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (a[v[i] + v[j]] == 0)
			{
				cout << 2 << '\n';
				cout << v[i] << ' ' << v[j] << '\n';
				return 0;
			}
		}
	}
	if (cnt) v.push_back(1);
	cout << 1 << '\n';
	cout << v.back() << '\n';

	return 0;
}