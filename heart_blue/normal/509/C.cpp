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
const int N = 1e5 + 10;

vector<string> vs;
string getans(string &s, int sum)
{
	string ret;
	if (sum % 9) ret.push_back('0' + sum % 9);
	ret += string(sum / 9, '9');
	if ((sum + 8) / 9 > s.length())
	{
		return ret;
	}
	int tot = 0;
	pair<int, int> key = { -1,-1 };
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = s[i] + 1; j <= '9'; j++)
		{
			int rest = s.length() - i - 1;
			if (sum < tot + j - '0' || rest * 9 + tot + j - '0' < sum) continue;
			key = { i,j };
			break;
		}
		tot += s[i] - '0';
	}
	if (key.first == -1) ret = "1" + string(s.length(), '0');
	else
	{

		ret = s.substr(0, key.first);
		ret.push_back(key.second);
		ret += string(s.length() - ret.length(), '0');
	}
	for (auto &c : ret) sum -= c - '0';
	for (int i = ret.length() - 1; i >= 0 && sum > 0; i--)
	{
		int o = min(9, sum);
		sum -= o;
		ret[i] = o + '0';
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string ans = "0";
	for (int i = 1; i <= n; i++)
	{
		int sum;
		cin >> sum;
		ans = getans(ans, sum);
		cout << ans << endl;
	}


	return 0;
}