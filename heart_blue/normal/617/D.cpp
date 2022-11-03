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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ax, bx, cx;
	int ay, by, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	if (ax == bx && cx == bx)
	{
		cout << 1 << endl;
		return 0;
	}
	if (ay == by && cy == by)
	{
		cout << 1 << endl;
		return 0;
	}
	vector<pair<int, int>> vp;
	vp.push_back({ ax,ay });
	vp.push_back({ bx,by });
	vp.push_back({ cx,cy });
	sort(vp.begin(), vp.end());
	do
	{
		if (vp[0].first == vp[1].first)
		{
			int o1 = vp[0].second;
			int o2 = vp[1].second;
			tie(o1, o2) = make_pair(min(o1, o2), max(o1, o2));
			if (vp[2].second <= o1 || vp[2].second >= o2)
			{
				cout << 2 << endl;
				return 0;
			}
		}
		if (vp[0].second == vp[1].second)
		{
			int o1 = vp[0].first;
			int o2 = vp[1].first;
			tie(o1, o2) = make_pair(min(o1, o2), max(o1, o2));
			if (vp[2].first <= o1 || vp[2].first >= o2)
			{
				cout << 2 << endl;
				return 0;
			}
		}
		
	} while (next_permutation(vp.begin(), vp.end()));
	cout << 3 << endl;
	return 0;
}