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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
pair<int, string> getans(string &str, int cnt, int x)
{
	string tmp;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (cnt > 0 && (str[i] - '0') % 3 == x)
		{
			cnt--;
			continue;
		}
		tmp.push_back(str[i]);
	}
	if (cnt > 0 || tmp.empty()) return { 0,"1-" };
	while (tmp.size() > 1 && tmp.back() == '0') tmp.pop_back();
	return { (int)tmp.size(),tmp };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int sum = 0;
	for (auto &c : str) sum += c - '0';
	sum %= 3;
	if (sum == 0)
	{
		cout << str << endl;
		return 0;
	}
	string ans = max(getans(str, 1, sum), getans(str, 2, 3 - sum)).second;
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}