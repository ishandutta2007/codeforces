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
const int N = 1e6 + 10;
pair<LL, LL> check(string &str, char c)
{
	int cnt[2] = { 0,0 };
	LL ret[2] = { 0,0 };
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != c) continue;
		cnt[i & 1]++;
		if (i & 1)
		{
			ret[0] += cnt[0];
			ret[1] += cnt[1];
		}
		else
		{
			ret[0] += cnt[1];
			ret[1] += cnt[0];
		}
	}
	return { ret[0],ret[1] };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	auto ans1 = check(str, 'a');
	auto ans2 = check(str, 'b');
	cout << ans1.first + ans2.first << ' ' << ans1.second + ans2.second << endl;
	return 0;
}