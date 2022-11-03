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
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;

int x[N];
int y[N];
int a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n = 8;
	vector<int> vx, vy;
	for (int i = 0; i < 8; i++)
	{
		cin >> x[i] >> y[i];
		vx.push_back(x[i]);
		vy.push_back(y[i]);
	}
	sort(vx.begin(), vx.end());
	vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
	sort(vy.begin(), vy.end());
	vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
	if (vx.size() != 3 || vy.size() != 3)
	{
		cout << "ugly" << endl;
		return 0;
	}
	map<int, int> mx, my;
	for (int i = 0; i < 3; i++)
	{
		mx[vx[i]] = i;
		my[vy[i]] = i;
	}
	MEM(a, 0);
	int tot = 0;
	for (int i = 0; i < 8; i++)
	{
		int s = mx[x[i]];
		int t = my[y[i]];
		if (!a[s][t]) tot++;
		a[s][t] = 1;
	}
	if (tot != 8 || a[1][1] == 1) cout << "ugly" << endl;
	else cout << "respectable" << endl;
	return 0;
}