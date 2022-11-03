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
const int N = 1e6 + 10;
int ans[N];
void refrain(string &str)
{
	for (int i = 1; i < str.length(); i += 2)
	{
		str[i] = 25 - (str[i] - 'A') + 'A';
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pair<string, int>> vp;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		refrain(str);
		vp.emplace_back(str, i);
	}
	sort(vp.begin(), vp.end());
	for (auto& p : vp)
	{
		printf("%d ", p.second + 1);
	}
	return 0;
}