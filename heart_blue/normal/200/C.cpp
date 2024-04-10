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
const int N = 3e2 + 10;
struct Node
{
	string name;
	int score;
	int goals;
	int dif;
	Node() 
	{
		name = "";
		score = 0;
		goals = 0;
		dif = 0;
	}
	bool operator < (const Node& node) const
	{
		if (score != node.score) return score > node.score;
		if (dif != node.dif) return dif > node.dif;
		if (goals != node.goals) return goals > node.goals;
		return name < node.name;
	}
};
map<pair<string, string>, pair<int, int>> ms;
bool check()
{
	map<string, Node> mn;
	for (auto& p : ms)
	{
		string s1, s2;
		int x, y;
		tie(s1, s2) = p.first;
		tie(x, y) = p.second;
		if (s1 > s2) continue;
		if (!mn.count(s1)) mn[s1].name = s1;
		if (!mn.count(s2)) mn[s2].name = s2;
		mn[s1].dif += x - y;
		mn[s2].dif += y - x;
		mn[s1].goals += x;
		mn[s2].goals += y;
		if (x > y) mn[s1].score += 3;
		if (x == y) mn[s1].score++, mn[s2].score++;
		if (x < y) mn[s2].score += 3;
	}
	vector<Node> v;
	for (auto& p : mn) v.push_back(p.second);
	sort(v.begin(), v.end());
	if (v[0].name == "BERLAND" || v[1].name == "BERLAND") return true;
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string key = "BERLAND";
	vector<string> vs;
	map<string, int> cnt;
	for (int i = 0; i < 5; i++)
	{
		string s1, s2;
		int x, y;
		cin >> s1 >> s2;
		scanf("%d:%d", &x, &y);
		ms[{s1, s2}] = { x,y };
		ms[{s2, s1}] = { y,x };
		cnt[s1]++;
		cnt[s2]++;
	}
	for (auto& p : cnt)
	{
		if (p.second == 2)
			vs.push_back(p.first);
	}
	string s1 = vs[0], s2 = vs[1];
	if (s1 != key) swap(s1, s2);
	pair<int, int> ans = { int(INF),int(INF) };
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 0; j < i; j++)
		{
			ms[{s1, s2}] = { i,j };
			ms[{s2, s1}] = { j,i };
			if (check())
			{
				ans = min(ans, { i - j,j });
			}
		}
	}
	if (ans.first == INF) puts("IMPOSSIBLE");
	else printf("%d:%d\n", ans.first + ans.second, ans.second);
	return 0;
}