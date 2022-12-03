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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string str;
	cin >> str;
	if (count(str.begin(), str.end(), '0') == n)
	{
		puts("0");
		return 0;
	}
	if (count(str.begin(), str.end(), '1') == n)
	{
		puts(str.c_str());
		return 0;
	}
	str = str.substr(str.find_first_of('1'));
	n = str.length();
	string ans = str;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '0')
			v.push_back(i);
	}
	int o = v[0];
	int len = n - o;
	for (auto& x : v)
		x -= o;
	int maxv = -1;
	vector<int> v1;
	for (int i = 0; i + len <= n; i++)
		v1.push_back(i);
	for (int i = 0; i < v.size(); i++)
	{
		vector<int> v2;
		for (auto& x : v1)
		{
			if (str[x + v[i]] == '1')
			{
				v2.push_back(x);
			}
		}
		if (!v2.empty())
		{
			v1.swap(v2);
			ans[v[i] + o] = '1';
		}
	}
	puts(ans.c_str());

	return 0;
}