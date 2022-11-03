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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 6e7 + 10;
struct Node
{
	int sz;
	Node* sons[2];
	Node()
	{
		sz = 0;
		sons[0] = sons[1] = nullptr;
	}
};
class ACAuto
{
public:
	static const int M = 2;
	static const int K = 29;
	int k;
	Node* rt;
	void init()
	{
		rt = newnode();
	}
	Node* newnode()
	{
		return new Node();
	}
	void add(int x)
	{
		Node* o = this->rt;
		for (int i = K; i >= 0; i--)
		{
			Node* &t = o->sons[x >> i & 1];
			if (t == nullptr) t = newnode();
			o = t;
			o->sz++;
		}
	}
	int solve(int x, int k, Node* o = nullptr, int cur = K)
	{
		if (o == nullptr)
		{
			o = rt;
		}
		int ret = 0;
		if (cur == -1)
		{
			return x >= k ? o->sz : 0;
		}
		int o1 = x >> cur & 1;
		int o2 = k >> cur & 1;
		for (int j = 0; j < 2; j++)
		{
			if (o->sons[j] == nullptr) continue;
			if ((o1 ^ j) > o2)
			{
				ret += o->sons[j]->sz;
			}
			else if ((o1 ^ j) == o2)
			{
				ret += solve((j << cur) ^ x, k, o->sons[j], cur - 1);
			}
		}
		return ret;
	}
} ac;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	int sum = 0;
	ac.init();
	ac.add(sum);
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		sum ^= x;
		ans += ac.solve(sum, k);
		ac.add(sum);
	}
	printf("%lld\n", ans);
	return 0;
}