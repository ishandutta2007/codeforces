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
const int N = 1e6 + 10;
int flag[N];
vector<pair<int, int>> vp;
int dis(pair<int, int> &p1, pair<int, int> &p2)
{
	int dx = p1.first - p2.first;
	int dy = p1.second - p2.second;
	return dx*dx + dy*dy;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	MEM(flag, 0);
	if (ax > bx) swap(ax, bx);
	if (ay > by) swap(ay, by);
	for (int i = ay; i <= by; i++)
	{
		vp.push_back({ bx,i });
		vp.push_back({ ax,i });
	}
	for (int i = ax + 1; i < bx; i++)
	{
		vp.push_back({ i,ay });
		vp.push_back({ i,by });
	}
	int n;
	cin >> n;
	while (n--)
	{
		pair<int, int> p;
		int r;
		cin >> p.first >> p.second >> r;
		for (int i = 0; i < vp.size(); i++)
		{
			if (dis(vp[i], p) <= r*r) 
				flag[i] = 1;
		}
	}
	int ans = vp.size();
	for (int i = 0; i < vp.size(); i++)
	{
		ans -= flag[i];
	}
	cout << ans << endl;
	return 0;
}