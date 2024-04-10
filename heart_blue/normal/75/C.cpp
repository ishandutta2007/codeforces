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
const int N = 3e5 + 10;
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n%m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b;
	int n;
	cin >> a >> b >> n;
	int g = gcd(a, b);
	vector<int> v;
	for (int i = 1; i*i <= g; i++)
	{
		if (g%i != 0) continue;
		v.push_back(i);
		if (g / i != i) v.push_back(g / i);
	}
	sort(v.begin(), v.end());
	while (n--)
	{
		int l, r;
		cin >> l >> r;
		if (lower_bound(v.begin(), v.end(), l) == v.end())
		{
			cout << -1 << '\n';
		}
		else
		{
			
			int x = *(--upper_bound(v.begin(), v.end(), r));
			if (x < l) x = -1;
			cout << x << '\n';
		}
	}
	return 0;
}