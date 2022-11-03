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
const int N = 2e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<tuple<int, int, int, int, int >, int> mc;
	int k;
	int ans = 0;
	string str;
	cin >> str >> k;
	queue<tuple<int, int, int, int, int>> q;
	q.push({ 0,0,k, 1,0 });
	mc[{0, 0, k, 1, 0}] = 1;
	while (!q.empty())
	{
		int pos, x, r, o, c;
		tie(pos, x, r, o, c) = q.front();
		q.pop();
		if (x == str.length())
		{
			if (r == 0) ans = max(ans, abs(pos));
			continue;
		}
		int cc = c;
		for (int i = r - 1; i >= 0; i--)
		{
			cc ^= 1;
			if (mc.count({ pos,x,i,o,cc })) continue;
			mc[{pos, x, i, o, cc}] = 1;
			q.push({ pos,x,i,o,cc });
		}
		int ch = str[x];
		if (c == 1)
		{
			if (ch == 'F') ch = 'T';
			else ch = 'F';
		}
		if (ch == 'F')
		{
			pos += o;
		}
		else
		{
			o = -o;
		}
		if (mc.count({ pos,x + 1,r,o,0 })) continue;
		mc[{pos, x + 1, r, o, 0}] = 1;
		q.push({ pos,x + 1,r,o,0 });
	}
	cout << ans << endl;
	return 0;
}