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
const int N = 7e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int o1 = str.find_first_of('[');
	int o4 = str.find_last_of(']');
	if(o1 == str.npos || o4 == str.npos)
	{
		puts("-1");
		return 0;
	}
	int l = INF, r = 0;
	for(int i = o1; i < o4; i++)
	{
		if(str[i] == ':')
			l = min(l, i), r = max(r, i);
	}
	if (l >= r)
	{
		puts("-1");
		return 0;
	}
	int ans = 4;
	ans += count(str.begin() + l, str.begin() + r, '|');
	cout << ans << endl;
	return 0;
}