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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e6 + 10;
class ACAuto
{
public:
	static const int M = 2;
	static const int K = 17;
	int ch[N][2];
	int k;
	void init()
	{
		k = 0;
		newnode();
	}
	int newnode()
	{
		MEM(ch[k], 0);
		return k++;
	}

	void add(int x)
	{
		int o = 0;
		for (int i = K - 1; i >= 0; i--)
		{
			int& t = ch[o][x >> i & 1];
			if (t == 0) t = newnode();
			o = t;
		}
	}
	int getmin(int x)
	{
		int o = 0;
		for (int i = K - 1; i >= 0; i--)
		{
			if (ch[o][0] == 0) o = ch[o][1], x ^= 1 << i;
			else if (ch[o][1] == 0) o = ch[o][0];
			else
			{
				o = ch[o][x >> i & 1];
				x ^= (x >> i & 1) << i;
			}
		}
		return x;
	}
	int getmax(int x)
	{
		int o = 0;
		for (int i = K - 1; i >= 0; i--)
		{
			if (ch[o][0] == 0) o = ch[o][1], x ^= 1 << i;
			else if (ch[o][1] == 0) o = ch[o][0];
			else
			{
				o = ch[o][(x >> i & 1) ^ 1];
				x ^= ((x >> i & 1) ^ 1) << i;
			}
		}
		return x;
	}
} ac;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);

	while (ncase--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		int n = r - l + 1;
		ac.init();
		vector<int> v;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			ac.add(x);
			v.push_back(x ^ l);
			v.push_back(x ^ r);
		}
		int ans = -1;
		for (auto& x : v)
		{
			int ql = ac.getmin(x);
			int qr = ac.getmax(x);
			if (ql == l && r == qr)
			{
				ans = x;
				break;
			}
		}
		printf("%d\n", ans);


	}
	return 0;
}