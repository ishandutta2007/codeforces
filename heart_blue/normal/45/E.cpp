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
const int N = 5e2 + 10;
int cnt1[N];
int cnt2[N];
vector<string> vs1, vs2;
int flag1[N];
int flag2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vs1.resize(n);
	vs2.resize(n);
	for (auto& s : vs1)
	{
		cin >> s;
		cnt1[s.front()]++;
	}
	for (auto& s : vs2)
	{
		cin >> s;
		cnt2[s.front()]++;
	}
	typedef tuple<string, int, int> Node;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	for (int i = 0; i < vs1.size(); i++)
	{
		for (int j = 0; j < vs2.size(); j++)
		{
			pq.emplace(vs1[i] + " " + vs2[j], i, j);
		}
	}
	int cur = 0;
	while (!pq.empty())
	{
		auto [str, i, j] = pq.top();
		pq.pop();
		if (flag1[i] || flag2[j]) continue;
		char c1 = vs1[i].front();
		char c2 = vs2[j].front();
		if (c1 == c2)
		{
			if (cur++) printf(", ");
			printf("%s", str.c_str());
			cnt1[c1]--;
			cnt2[c2]--;
			flag1[i] = 1;
			flag2[j] = 1;
			continue;
		}
		if (cnt1[c1] <= cnt2[c1]) continue;
		if (cnt1[c2] >= cnt2[c2]) continue;
		cnt1[c1]--;
		cnt2[c2]--;
		if (cur++) printf(", ");
		printf("%s", str.c_str());
		flag1[i] = flag2[j] = 1;
	}
	puts("");
	return 0;
}