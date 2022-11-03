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
const int N = 1e4 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	string ans;
	cin >> str;
	for (auto &c : str)
	{
		int l = ans.length();
		if (l >= 2)
		{
			if (ans[l - 1] == ans[l - 2] && ans[l - 1] == c) continue;
		}
		if (l >= 3)
		{
			if (ans[l - 3] == ans[l - 2] && ans[l - 1] == c) continue;
		}
		ans.push_back(c);
	}
	cout << ans << endl;
	return 0;
}