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
const int N = 1e3 + 10;

int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<pair<pair<int, int>, int>> vp1;
	vector<pair<int, int>> vp2;
	vector<pair<int, int>> ans;
	int n;
	cin >> n;
	MEM(flag, 0);
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		vp1.push_back({ {y,x},i });
	}
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		vp2.push_back({ x,i });
	}
	sort(vp1.rbegin(), vp1.rend());
	sort(vp2.begin(), vp2.end());
	LL tot = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (flag[j]) continue;
			if (vp2[j].first >= vp1[i].first.second)
			{
				flag[j] = 1;
				ans.push_back({ vp1[i].second, vp2[j].second });
				tot += vp1[i].first.first;
				break;
			}
		}
	}
	cout << ans.size() << ' ' << tot << endl;
	for (auto &p : ans)
	{
		cout << p.first << ' ' << p.second << endl;
	}
	return 0;
}