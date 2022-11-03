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
bool check(string str)
{
	int l = 0;
	int r = str.length() - 1;
	while (l <= r)
	{
		if (str[l] != str[r]) return false;
		l++, r--;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int ans = 0;
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 1; i + j <= str.length(); j++)
		{
			if (check(str.substr(i, j))) continue;
			ans = max(ans, j);
		}
	}
	cout << ans << endl;
	return 0;
}