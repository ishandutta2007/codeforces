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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		vector<int> v;
		int a = 0, b = 0;
		int n;
		cin >> n;
		while (n--)
		{
			string str;
			cin >> str;
			int o = count(str.begin(), str.end(), '0');
			a += o;
			b += str.length() - o;
			v.push_back(str.length());
		}
		sort(v.begin(), v.end());
		int ans = 0;
		for (auto& x : v)
		{
			if (a < b) swap(a, b);
			if (x & 1)
			{
				if (a & 1) a--;
				else if (b & 1) b--;
				else a--;
				x--;
			}
			while (x && (a > 1 || b > 1))
			{
				if (a < b) swap(a, b);
				x -= 2, a -= 2;
			}
			if (x == 0) ans++;
			else break;
		}
		cout << ans << endl;
	}
	return 0;
}