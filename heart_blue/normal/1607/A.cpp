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
char str[N];
class SegmentTree
{
public:
	pair<int, int> key[N * 4];
	int ql, qr, qx;

	void set(int l, int r, int x = 0)
	{
		ql = l, qr = r, qx = x;
	}
	pair<int, int> combine(const pair<int, int>& p1, const pair<int, int>& p2)
	{
		if (p1.first == 0 || p2.first == 0) return max(p1, p2);
		int len1, o1;
		int len2, o2;
		tie(len1, o1) = p1;
		tie(len2, o2) = p2;
		o1 ^= (len1 & 1) ^ 1;
		if (o1 != o2)
		{
			o1 ^= (len1 & 1) ^ 1;
			return { len1 + len2, o1 };
		}
		else
		{
			o1 ^= (len1 & 1) ^ 1;
			if (len1 == len2) return { 0,0 };
			else if (len1 > len2) return { len1 - len2,o1 };
			else return { len2 - len1,o2 ^ (len1 & 1) };
		}
	}
	void build(int l, int r, int o = 1)
	{
		if (l == r)
		{
			key[o] = { 1, (str[l] == '(' || str[l] == ')') ? 0 : 1 };
			return;
		}
		int mid = (l + r) / 2;
		build(l, mid, o << 1);
		build(mid + 1, r, o << 1 | 1);
		key[o] = combine(key[o << 1], key[o << 1 | 1]);
	}
	pair<int, int> query(int l, int r, int o = 1)
	{
		if (ql <= l && r <= qr)
		{
			return key[o];
		}
		pair<int, int> ret1, ret2;
		ret1 = ret2 = { 0,0 };
		int mid = (l + r) / 2;
		if (ql <= mid) ret1 = query(l, mid, o << 1);
		if (mid < qr) ret2 = query(mid + 1, r, o << 1 | 1);
		return combine(ret1, ret2);
	}
} st;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string s1, s2;
		map<char, int> mc;
		cin >> s1 >> s2;
		for (int i = 0; i < s1.length(); i++)
		{
			mc[s1[i]] = i;
		}
		int ans = 0;
		for (int i = 1; i < s2.length(); i++)
		{
			ans += abs(mc[s2[i]] - mc[s2[i - 1]]);
		}
		printf("%d\n", ans);
	}
	return 0;
}