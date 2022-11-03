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
#define MEM(x, y) memset((x),(y),sizeof(x))
const int INF = 1e9 + 7;
const int N = 1e5 + 10;
int p[N];
int flag[N];
int a[N];
int pos[N];
int key[N];
void init()
{
	int k = 0;
	for (int i = 2; i < N; i++)
	{
		if (flag[i]) continue;
		for (int j = i + i; j < N; j += i) flag[j] = 1;
		p[k++] = i;
	}
	for (int i = 4; i < N; i++)
	{
		for (int j = 0; p[j] < i; j++)
		{
			if (flag[i - p[j]]) continue;
			key[i] = p[j];
			break;
		}
	}
}
vector<pair<int, int>> ans;
void change(int x, int y)
{
	ans.push_back({ x,y });
	swap(a[x], a[y]);
	pos[a[x]] = x;
	pos[a[y]] = y;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	init();
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pos[a[i]] = i;
	}
	for (int i = n; i > 0; i--)
	{
		if (pos[i] == i) continue;
		int len = i - pos[i];
		if (flag[len + 1] == 0)
		{
			change(pos[i], i);
			continue;
		}
		int x = pos[i];
		if (len & 1)
		{
			change(x, x + 1);
			x++;
			len--;
		}
		change(x, x + key[len + 2] - 1);
		change(x + key[len + 2] - 1, i);
	}
	cout << ans.size() << endl;
	for (auto &p : ans)
	{
		cout << p.first << ' ' << p.second << '\n';
	}
	return 0;
}