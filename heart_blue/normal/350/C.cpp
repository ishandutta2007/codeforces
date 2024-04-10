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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const int INF = 1e9 + 7;
const int N = 1e5 + 10;
vector<pair<int, int>> vp;
int op[N * 10];
int step[N * 10];
char dir[N * 10];
int k = 0;
void moveto(int x, int y, int dx, int dy)
{
	if (dx != 0)
	{
		op[k] = 1;
		step[k] = abs(dx);
		if (dx > 0) dir[k++] = 'R';
		else dir[k++] = 'L';
	}
	if (dy != 0)
	{
		op[k] = 1;
		step[k] = abs(dy);
		if (dy > 0) dir[k++] = 'U';
		else dir[k++] = 'D';
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vp.resize(n);
	for (auto &p : vp) cin >> p.first >> p.second;
	sort(vp.begin(), vp.end(), [](pair<int, int> p1, pair<int, int> p2) -> bool
	{
		if (abs(p1.first) != abs(p2.first)) return abs(p1.first) < abs(p2.first);
		return abs(p1.second) < abs(p2.second);
	});
	for (auto &p : vp)
	{
		int x, y;
		tie(x, y) = p;
		moveto(0, 0, x, y);
		op[k++] = 2;
		moveto(x, y, -x, -y);
		op[k++] = 3;
	}
	printf("%d\n", k);
	for (int i = 0; i < k; i++)
	{
		printf("%d", op[i]);
		if (op[i] == 1)
		{
			printf(" %d %c", step[i], dir[i]);
		}
		puts("");
	}
	
	return 0;
}