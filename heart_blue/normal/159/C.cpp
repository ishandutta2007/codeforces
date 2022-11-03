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
const int N = 2e5 + 10;
class TreeArray
{
public:
	int a[N];
	TreeArray()
	{
		MEM(a, 0);
	}
	void add(int x, int y = 1)
	{
		while (x < N)
		{
			a[x] += y;
			x += lowbit(x);
		}
	}
	int sum(int x)
	{
		int ret = 0;
		while (x)
		{
			ret += a[x];
			x -= lowbit(x);
		}
		return ret;
	}
	int lowbit(int x)
	{
		return x&-x;
	}
	int find(int k)
	{
		int l = 1, r = N - 1;
		int ret = 0;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (sum(mid) >= k) ret = mid, r = mid - 1;
			else l = mid + 1;
		}
		return ret;
	}
} ta[26];
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str, s;
	int n;
	cin >> n;
	cin >> str;
	while (n--) s += str;
	n = s.length();
	for (int i = 0; i < n; i++)
	{
		v[s[i] - 'a'].push_back(i);
	}
	for (int i = 0; i < 26; i++)
	{
		for (int j = 1; j <= v[i].size(); j++)
		{
			ta[i].add(j);
		}
	}
	int q;
	cin >> q;
	while (q--)
	{
		char ch;
		int x;
		cin >> x >> ch;
		ch -= 'a';
		int k = ta[ch].find(x);
		ta[ch].add(k, -1);
		s[v[ch][k - 1]] = ' ';
	}
	for (auto &c : s)
	{
		if (isalpha(c)) putchar(c);
	}
	return 0;
}