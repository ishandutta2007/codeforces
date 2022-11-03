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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		string str;
		cin >> str;
		LL ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == 'L') ans += i;
			else ans += n - i - 1;
		}
		vector<LL> v;
		v.push_back(ans);
		int l = 0, r = n - 1;
		while (l < r)
		{
			if (str[l] == 'L')
			{
				ans += -l + n - l - 1;
				v.push_back(ans);
			}
			if (str[r] == 'R')
			{
				ans -= n - r - 1 - r;
				v.push_back(ans);
			}
			l++, r--;
		}
		LL last = v.back();
		while (v.size() < n + 1)
			v.push_back(last);
		for (int i = 1; i < v.size(); i++)
			printf("%lld%c", v[i], " \n"[i + 1 == v.size()]);
	}
	return 0;
}