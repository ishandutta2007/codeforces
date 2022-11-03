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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int o = str.find('e');
	string ans = str.substr(0, o);
	string p = str.substr(o + 1);
	int b = 0;
	for (auto &c : p) b = b * 10 + (c - '0');
	while (b--)
	{
		int o = ans.find('.');
		if (o == -1) ans.push_back('0');
		if (o < ans.length() - 1) swap(ans[o], ans[o + 1]);
		if (ans.back() == '.') ans.pop_back();
	}
	for (int i = 0; i < ans.length(); i++)
	{
		if (ans[i] != '0')
		{
			ans = ans.substr(i);
			break;
		}
	}
	if (ans.find('.') != -1) while (ans.back() == '0') ans.pop_back();
	if (!ans.empty() && ans.front() == '.') ans = '0' + ans;
	if (ans.back() == '.') ans.pop_back();
	cout << ans << endl;

	return 0;
}