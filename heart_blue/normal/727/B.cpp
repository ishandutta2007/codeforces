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
const int N = 1e5 + 10;
LL check(string str)
{
	int n = str.length();
	if (n >= 3)
	{
		if (str[n - 3] != '.') str += ".00";
	}
	else str += ".00";
	for (auto &c : str) if (c == '.') c = ' ';
	stringstream sin(str);
	LL ret = 0;
	int x = 0;
	vector<int> v;
	while (sin >> x) v.push_back(x);
	for (int i = 0; i < v.size(); i++)
	{
		ret *= 100;
		if (i + 1 != v.size()) ret *= 10;
		ret += v[i];
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	for (auto &c : str) if (isalpha(c)) c = ' ';
	stringstream sin(str);
	LL sum = 0;
	while (sin >> str)
	{
		sum += check(str);
	}
	vector<int> ans;
	ans.push_back(sum % 100);
	sum /= 100;
	while (sum >= 1000)
	{
		ans.push_back(sum % 1000);
		sum /= 1000;
	}
	printf("%d", sum);
	while (ans.size() != 1) printf(".%03d", ans.back()), ans.pop_back();
	if(ans.back()) printf(".%02d\n", ans.back());
	return 0;
}