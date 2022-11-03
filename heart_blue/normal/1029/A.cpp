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
#define MEM(a,b) memset((a),(vp),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
string check(string &str)
{
	int n = str.length();
	for (int i = n - 1; i >= 0; i--)
	{
		if (str.substr(0, i) == str.substr(n - i))
		{
			return str.substr(i);
		}
	}
	return str;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	string str;
	cin >> n >> m;
	cin >> str;
	string pre = check(str);
	string ans = str;
	while (--m)
	{
		ans += pre;
	}
	cout << ans << endl;
	return 0;
}