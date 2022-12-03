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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int ask(int a, int b)
{
	cout << "? " << a << ' ' << b << endl;
	int ret;
	cin >> ret;
	return ret;
}
/*
1 2 3 4 5 6 7 8
0 1 0 2
*/
int query(int a, int b)
{
	if (ask(a, b) == 1) return a;
	else return b;
}
int query(int a, int b, int c, int d)
{
	int ret1 = ask(a, c);
	if (ret1 == 0)
	{
		int ret2 = ask(b, d);
		if (ret2 == 1) return b;
		else return d;
	}
	if (ret1 == 2) swap(a, c), swap(b, d);
	if (ask(a, d) == 1) return a;
	else return d;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		n = 1 << n;
		vector<int> v;
		for (int i = 1; i <= n; i++) v.push_back(i);
		while (v.size() > 1)
		{
			if (v.size() == 2)
			{
				int x = query(v[0], v[1]);
				v.clear();
				v.push_back(x);
				continue;
			}
			vector<int> key;
			for (int i = 0; i < v.size(); i += 4)
			{
				key.push_back(query(v[i], v[i + 1], v[i + 2], v[i + 3]));
			}
			v.swap(key);
		}
		cout << "! " << v[0] << endl;
	}
	return 0;
}