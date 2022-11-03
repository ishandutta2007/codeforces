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
const int N = 1e4 + 10;
int a[N];

int ask(int t, int i, int j, int x)
{
	cout << "? " << t << ' ' << i << ' ' << j << ' ' << x << endl;
	int ret;
	cin >> ret;
	return ret;
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
		int id = n;
		for (int i = 1; i + 1 <= n; i += 2)
		{
			int ret = ask(2, i, i + 1, 1);
			if (ret == 1)
			{
				id = i;
				break;
			}
			if (ret == 2)
			{
				ret = ask(2, i + 1, i, 1);
				if (ret == 1)
				{
					id = i + 1;
					break;
				}
			}
		}
		a[id] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (id == i) continue;
			a[i] = ask(1, id, i, n - 1);
		}
		cout << "!";
		for (int i = 1; i <= n; i++)
			cout << ' ' << a[i];
		cout << endl;
	}
	return 0;
}