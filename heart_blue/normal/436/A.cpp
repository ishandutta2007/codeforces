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
const double eps = 1e-10;
const int N = 2010;
class Candy
{
public:
	int t, h, m;
	bool operator < (const Candy & c) const
	{
		return h < c.h;
	}
};
vector<Candy> vc;
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);

	MEM(flag, 0);
	int n, x;
	cin >> n >> x;
	vc.resize(n);
	for (int i = 0; i < n; i++) cin >> vc[i].t >> vc[i].h >> vc[i].m;
	sort(vc.begin(), vc.end());
	int cur = 0;
	MEM(flag, 0);
	int ans = 0;
	int cnt = 0;
	int h = x;
	for (int i = 0; i < n; i++)
	{
		int tmp = -1;
		int key = -1;
		for (int j = 0; j < n; j++)
		{
			if (flag[j]) continue;
			if (vc[j].t != cur) continue;
			if (vc[j].h > h) continue;
			if (tmp < vc[j].m)
			{
				tmp = vc[j].m;
				key = j;
			}
		}
		if (key == -1) break;
		h += vc[key].m;
		flag[key] = 1;
		cnt++;
		cur ^= 1;
	}
	ans = max(ans, cnt);
	h = x;
	cur = 1;
	cnt = 0;
	MEM(flag, 0);
	for (int i = 0; i < n; i++)
	{
		int tmp = -1;
		int key = -1;
		for (int j = 0; j < n; j++)
		{
			if (flag[j]) continue;
			if (vc[j].t != cur) continue;
			if (vc[j].h > h) continue;
			if (tmp < vc[j].m)
			{
				tmp = vc[j].m;
				key = j;
			}
		}
		if (key == -1) break;
		h += vc[key].m;
		flag[key] = 1;
		cnt++;
		cur ^= 1;
	}
	ans = max(ans, cnt);
	cout << ans << endl;
	return 0;
}