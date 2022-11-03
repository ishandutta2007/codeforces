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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 31;

pair<int, int> check(int x1, int x2, int x3, int y1, int y2, int y3)
{
	return{ x1 + x3 - x1 + x2 - x1,y1 + y3 - y1 + y2 - y1 };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	map<pair<int, int>, int> m;
	m[check(x1, x2, x3, y1, y2, y3)] = 1;
	m[check(x2, x1, x3, y2, y1, y3)] = 1;
	m[check(x3, x1, x2, y3, y1, y2)] = 1;
	cout << m.size() << endl;
	for (auto &p : m)
	{
		cout << p.first.first << ' ' << p.first.second << endl;
	}
	return 0;
}