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
const int N = 2e5 + 10;
pair<int, int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int k;
	cin >> k;
	int maxv = 0;
	int minv = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (isalpha(str[i])) v[i] = { 1,1 };
		else if (str[i] == '?') v[i - 1] = { 0,1 };
		else v[i - 1] = { 0,200 };
	}
	for (int i = 0; i < str.length(); i++)
	{
		minv += v[i].first;
		maxv += v[i].second;
	}
	if (k < minv || k > maxv) puts("Impossible"), exit(0);
	k -= minv;
	for (int i = 0; i < str.length(); i++)
	{
		if (v[i].first == 1)
		{
			putchar(str[i]);
			continue;
		}
		int o = min(v[i].second, k);
		k -= o;
		while (o--) putchar(str[i]);
	}
	return 0;
}