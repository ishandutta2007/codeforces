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
int getans(const string& str)
{
	int ret = 1;
	for (auto& c : str) ret *= (c - '0');
	return ret;
}
int getans(int n)
{
	int ret = 1;
	while (n)
	{
		ret *= n % 10;
		n /= 10;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int ans = getans(str);
	int x = 0;
	for (int i = 0; i < str.length(); i++)
	{
		x = x * 10 + str[i] - '0';
		ans = max(ans, getans(x - 1) * getans(string(str.length() - i - 1, '9')));
	}
	cout << ans << endl;
	return 0;
}