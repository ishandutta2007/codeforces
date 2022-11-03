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
const int N = 2e3 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, c;
	cin >> n >> m >> c;
	MEM(a, 0);
	int cnt = 0;
	while (m--)
	{
		int x;
		cin >> x;
		int o = x*n / c;
		o = min(o, n);
		o = max(o, 1);
		if (x == 1) o = 1;
		if (x == n) o = n;
		if (a[o] == 0)
		{
			a[o] = x;
			cout << o << endl;
			cnt++;
		}
		else
		{
			int o1 = o, o2 = o;
			while (o2 <= n && a[o2] != 0) o2++;
			while (o1 > 0 && a[o1] != 0) o1--;
			o1++, o2--;
			if (o2 < n && a[o2] <= x)
			{
				a[o2 + 1] = x;
				cout << o2 + 1 << endl;
				cnt++;
				continue;
			}
			if (o1 > 1 && a[o1] >= x)
			{
				a[o1-1] = x;
				cout << o1-1 << endl;
				cnt++;
				continue;
			}
			
			int key = o1;
			for (int i = o2; i >= o1; i--)
			{
				if (a[i] <= x)
				{
					key = i;
					break;
				}
			}
			a[key] = x;
			cout << key << endl;
		}
	}
	//cout << "****" << endl;
	//for (int i = 1; i <= n; i++) cout << a[i] << endl;
	return 0;
}