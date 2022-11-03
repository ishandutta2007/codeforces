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
const int N = 3e5 + 10;

map<int, int> mb, ms;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, s;
	cin >> n >> s;
	char c;
	int x, y;
	while (n--)
	{
		cin >> c >> x >> y;
		if (c == 'B') mb[x] += y;
		else ms[x] += y;
	}
	int o = 0;
	while (ms.size() > s) ms.erase(ms.rbegin()->first);
	for (auto iter = ms.rbegin(); iter != ms.rend(); iter++)
	{
		cout << "S " << iter->first << ' ' << iter->second << endl;
		if (++o == s) break;
	}
	o = 0;
	for (auto iter = mb.rbegin(); iter != mb.rend(); iter++)
	{
		cout << "B " << iter->first << ' ' << iter->second << endl;
		if (++o == s) break;
	}
	return 0;
}