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
vector<int> v[2];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		if (x % 3) v[1].push_back(i);
		else v[0].push_back(i);
	}
	if (v[0].empty() || v[1].empty())
	{
		puts("1");
		puts((string(n / 2, '0') + string(n / 2, '1')).c_str());
		return 0;
	}
	string str(n, '0');
	if (v[0].size() < v[1].size())
		for (auto& x : v[0])
			str[x] = '1';
	else
		for (auto& x : v[1])
			str[x] = '1';
	int rest = n / 2 - min(v[0].size(), v[1].size());
	for (int i = 0; i < n && rest; i++)
	{
		if (str[i] == '0')
			str[i] = '1', rest--;
	}
	if (v[0].size() < v[1].size())
		puts("0");
	else
		puts("2");
	puts(str.c_str());
	return 0;
}