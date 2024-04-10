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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	string s;
	while (cin >> s)
		str += s;
	for (auto& c : str)
	{
		if (c == '<') c = ' ';
		if (c == '>') c = ' ';
	}
	vector<string> vs;
	vector<int> ans;
	stringstream sin(str);
	while (sin >> str)
	{
		if (str[0] == '/')
		{
			if (str == "/table")
			{
				ans.push_back(a[vs.size() - 1]);
			}
			else
			{
				a[vs.size() - 2] += a[vs.size() - 1];
			}
			vs.pop_back();
			a[vs.size()] = 0;
		}
		else
		{
			if (str == "td") a[vs.size()] = 1;
			else a[vs.size()] = 0;
			vs.push_back(str);
		}
	}
	sort(ans.begin(), ans.end());
	for (auto& x : ans)
		printf("%d ", x);
	return 0;
}