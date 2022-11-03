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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;

string rebuild(string str)
{
	if (str.length() > 9) return str.substr(0, 4) + "*" + str.substr(str.length() - 4);
	else return str;
}
int getans(const string str)
{
	int ans = 0;
	for (int i = 0; i + 4 <= str.length(); i++)
	{
		if (str.substr(i, 4) == "haha")
			ans++;
	}
	return ans;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		map<string, string> ms;
		map<string, LL> mc;
		string str, s1, s2;
		string op;
		int n;
		cin >> n;
		while (n--)
		{
			cin >> str;
			cin >> op;
			if (op == ":=")
			{
				cin >> s1;
				mc[str] = getans(s1);
				ms[str] = rebuild(s1);
			}
			else
			{
				cin >> s1 >> op >> s2;
				string s3 = ms[s1] + ms[s2];
				mc[str] = mc[s1] + mc[s2] + getans(s3) - getans(ms[s1]) - getans(ms[s2]);
				ms[str] = rebuild(s3);
			}
		}
		printf("%lld\n", mc[str]);
	}
	return 0;
}