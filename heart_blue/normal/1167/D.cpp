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
const int N = 50 + 10;
vector<int> v;
bool check(string &str, int k)
{
	int a = 0;
	int b = 0;
	v.clear();
	for (auto &c : str)
	{
		if (c == '(')
		{
			if (a < k) a++, v.push_back(0);
			else b++, v.push_back(1);
		}
		else
		{
			if (b > 0) b--, v.push_back(1);
			else a--, v.push_back(0);
		}
		if (max(a, b) > k) return false;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string str;
	cin >> n >> str;
	int l = 0, r = str.length();
	int key = r;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(str, mid)) key = mid, r = mid - 1;
		else l = mid + 1;
	}
	check(str, key);
	for (auto &x : v) putchar(x + '0');
	return 0;
}