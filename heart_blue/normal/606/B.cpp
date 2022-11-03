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
const int N = 5e2 + 10;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
map<char, int> mc;
int flag[N][N];
void init()
{
	string str = "LRUD";
	for (int i = 0; i < str.length(); i++)
	{
		mc[str[i]] = i;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	MEM(flag, 0);
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	int tot = n*m - 1;
	vector<int> v;
	v.push_back(1);
	flag[x][y] = 1;
	string str;
	cin >> str;
	for (auto &c : str)
	{
		int o = mc[c];
		x += dx[o];
		y += dy[o];
		if (x < 1) x = 1;
		if (x > n) x = n;
		if (y < 1) y = 1;
		if (y > m) y = m;
		//cout << x << ' ' << y << endl;
		if (flag[x][y]) v.push_back(0);
		else
		{
			v.push_back(1);
			flag[x][y] = 1;
			tot--;
		}
	}
	v.back() += tot;
	for (auto &x : v) cout << x << ' ';
	return 0;
}