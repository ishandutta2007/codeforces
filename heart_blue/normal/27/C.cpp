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
class T
{
public:
	set<int> s;
	map<int, int> ms;
	void insert(int x)
	{
		ms[x]++;
		s.insert(x);
	}
	void erase(int x)
	{
		ms[x]--;
		if (ms[x] == 0)
		{
			ms.erase(x);
			s.erase(x);
		}
	}
	set<int>::iterator upper_bound(int x)
	{
		return s.upper_bound(x);
	}
	set<int>::iterator end()
	{
		return s.end();
	}
};
int a[N];
int idx(int l, int r, int x)
{
	int o = 1;
	for (int i = l; i <= r; i++)
	{
		if (a[i] == x)
		{
			o = i;
			break;
		}
	}
	return o;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	T s1, s2;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s2.insert(a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		s2.erase(a[i]);
		set<int>::iterator iter1, iter2;
		iter1 = s1.upper_bound(a[i]);
		iter2 = s2.upper_bound(a[i]);
		if (iter1 != s1.end() && iter2 != s2.end())
		{
			if (*iter1 > a[i] && *iter2 > a[i])
			{
				cout << 3 << endl;
				cout << idx(1, i, *iter1) << ' ' << i << ' ' << idx(i, n, *iter2) << endl;
				return 0;
			}
		}
		iter1 = s1.upper_bound(-INF);
		iter2 = s2.upper_bound(-INF);
		if (iter1 != s1.end() && iter2 != s2.end())
		{
			if (*iter1 < a[i] && *iter2 < a[i])
			{
				cout << 3 << endl;
				cout << idx(1, i, *iter1) << ' ' << i << ' ' << idx(i, n, *iter2) << endl;
				return 0;
			}
		}
		s1.insert(a[i]);
	}
	cout << 0 << endl;
	return 0;
}