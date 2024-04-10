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
const int N = 2e5 + 10;
vector<int> vp[10];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int sz;
		scanf("%d", &sz);
		vp[i].resize(sz);
		for (auto& x : vp[i])
			scanf("%d", &x);
	}
	map<vector<int>, int> mv, in;
	int m;
	scanf("%d", &m);
	while (m--)
	{
		vector<int> v(n);
		for (auto& x : v)
		{
			scanf("%d", &x);
			x--;
		}
		mv[v] = 1;
	}
	priority_queue < pair<int, vector<int>> > pq;
	{
		int sum = 0;
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			sum += vp[i].back();
			v.push_back(vp[i].size() - 1);
		}
		pq.emplace(sum, v);
		in[v] = 1;
	}
	while (!pq.empty())
	{
		auto [sum, v] = pq.top();
		pq.pop();
		if (!mv.count(v))
		{
			for (auto& x : v)
				printf("%d ", x + 1);
			puts("");
			break;
		}
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == 0) continue;
			sum -= vp[i][v[i]--];
			sum += vp[i][v[i]];
			if (!in.count(v))
			{
				in[v] = 1;
				pq.emplace(sum, v);
			}
			sum -= vp[i][v[i]++];
			sum += vp[i][v[i]];
		}
	}
	return 0;
}