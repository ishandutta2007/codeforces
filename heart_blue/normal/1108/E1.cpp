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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
int b[N];
int maxv[N];
vector<tuple<int, int, int>> vp;
pair<int, vector<int>> check(int n)
{
	reverse(a + 1, a + n + 1);
	int ans = 0, key = 0;
	for (int i = 1; i <= n; i++) b[i] = a[i];
	maxv[n] = b[n];
	for (int i = n - 1; i >= 1; i--)
	{
		maxv[i] = max(b[i], maxv[i + 1]);
	}
	for (auto& p : vp)
	{
		int l, r, pos;
		tie(r, l, pos) = p;
		p = make_tuple(n - l + 1, n - r + 1, pos);
	}
	sort(vp.begin(), vp.end());
	int ptr = 0;
	int minv = INF;
	for (int i = 1; i < n; i++)
	{
		minv = min(b[i], minv);
		while (ptr < vp.size() && get<0>(vp[ptr]) <= i)
		{
			int r, l;
			tie(r, l, ignore) = vp[ptr++];
			for (int j = l; j <= r; j++)
			{
				minv = min(minv, --b[j]);
			}
		}
		if (ans < maxv[i + 1] - minv)
			ans = maxv[i + 1] - minv, key = ptr;
	}
	vector<int> ret;
	for (int i = 0; i < key; i++) ret.push_back(get<2>(vp[i]));
	return { ans,ret };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++)
	{
		int l, r;
		cin >> l >> r;
		vp.push_back({ r,l,i });
	}
	auto ans = max(check(n), check(n));
	int l;
	vector<int> v;
	tie(l, v) = ans;
	cout << l << endl;
	cout << v.size() << endl;
	for (auto& x : v) cout << x << ' ';
	return 0;
}