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
char str[N];
int check(string& s, int pre = 1000)
{
	vector<int> ret;
	for (int i = 0; i < 4; i++)
	{
		string str = s;
		for (int j = '0'; j <= '9'; j++)
		{
			str[i] = j;
			ret.push_back(stoi(str));
		}
	}
	sort(ret.begin(), ret.end());
	while (ret.back() > 2011) ret.pop_back();
	auto iter = lower_bound(ret.begin(), ret.end(), pre);
	if (iter == ret.end()) puts("No solution"), exit(0);
	return *iter;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	vector<int> ans;
	int pre = 1000;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		ans.push_back(check(str, pre));
		pre = ans.back();
	}
	for (auto& x : ans)
		printf("%d\n", x);
	return 0;
}