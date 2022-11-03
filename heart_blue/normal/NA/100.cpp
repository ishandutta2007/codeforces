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
pair<int, string> getans(string str, char o, int k)
{
	for (auto &ch : str)
	{
		if (ch == o) k--;
	}
	if (k <= 0) return { 0,str };
	int ret = 0;
	for (int d = 1; d < 10; d++)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (k > 0 && str[i] == o + d)
			{
				ret += d;
				str[i] = o;
				k--;
			}
		}
		for (int i = str.length() - 1; i >= 0; i--)
		{
			if (k > 0 && str[i] == o - d)
			{
				ret += d;
				str[i] = o;
				k--;
			}
		}
	}
	return { ret,str };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	pair<int, string> ans = { (int)INF,"" };
	string str;
	cin >> str;
	for (int i = '0'; i <= '9'; i++)
		ans = min(ans, getans(str, i, k));
	cout << ans.first << endl;
	cout << ans.second << endl;
	return 0;
}