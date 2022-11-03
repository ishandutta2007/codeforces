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
LL cross(LL ax, LL ay, LL bx, LL by, LL cx, LL cy)
{
	return ax*by + bx*cy + cx*ay - ax*cy - bx*ay - cx*by;
}
int a[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int tot = 1000;
	vector<int> v;
	for (int i = 1; i <= n; i++) v.push_back(i);
	for (int i = 1; i <= n; i++) cin >> a[i];
	while (tot--)
	{
		random_shuffle(v.begin(), v.end());
		int x = v.front(), y = v.back();
		MEM(flag, 0);
		flag[x] = 1, flag[y] = 1;
		int key = -1;
		int cnt = 2;
		for (int i = 1; i <= n; i++)
		{
			if (flag[i]) continue;
			if (cross(x, a[x], y, a[y], i, a[i]) == 0)
			{
				cnt++;
				flag[i] = 1;
			}
			else key = i;
		}
		if (key == -1) continue;
		int offsetY = a[x] - a[key];
		int offsetX = x - key;
		for (int i = 1; i <= n; i++)
		{
			if (flag[i]) continue;
			if (cross(x, a[x], y, a[y], i + offsetX, a[i] + offsetY) == 0)
			{
				flag[i] = 1;
				cnt++;
			}
		}
		if (cnt == n)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}