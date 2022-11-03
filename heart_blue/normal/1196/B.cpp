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
const LL INF = 1e8 + 7;
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
		int n, k;
		cin >> n >> k;
		int sum = 0;
		vector<int> ans;
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			x &= 1;
			sum ^= x;
			if (sum && ans.size() < k)
			{
				ans.push_back(i);
				sum = 0;
			}
		}
		if (ans.size() < k || sum % 2 == 1)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
			ans.back() = n;
			for (auto& x : ans) cout << x << ' ';
			cout << endl;
		}
	}
	return 0;
}