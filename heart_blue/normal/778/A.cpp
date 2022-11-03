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
const int N = 2e5 + 10;

int flag[N];
int a[N];
string s1, s2;
bool check(int x)
{
	MEM(flag, 0);
	for (int i = 0; i < x; i++) flag[a[i]] = 1;
	int p = 0;
	for (int i = 0; i < s2.length(); i++)
	{
		while (p < s1.length())
		{
			if (flag[p] == 0 && s2[i] == s1[p]) break;
			p++;
		}
		if (p == s1.length()) return false;
		p++;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> s1 >> s2;
	int n = s1.length();
	int l = 0, r = n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
	}
	int ret = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid)) ret = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ret << endl;
	return 0;
}