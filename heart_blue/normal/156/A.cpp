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
int check(string &&s1, string &s2)
{
	int n = min(s1.length(), s2.length());
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			ret++;
	}
	return ret + max(0, (int)s2.length() - n);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s1, s2;
	cin >> s1 >> s2;
	s1 = string(2000, '*') + s1 + string(2000, '*');
	int ans = INF;
	for (int i = 0; i < s1.length(); i++)
	{
		ans = min(ans, check(s1.substr(i), s2));
	}
	cout << ans << endl;
	return 0;
}