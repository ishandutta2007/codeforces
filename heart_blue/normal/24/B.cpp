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
const int N = 2e5 + 10;
int a[N] = { 25, 18, 15, 12, 10, 8, 6, 4, 2, 1 ,0 };
struct Node
{
public:
	string name;
	int scores;
	int cnt[51];
	Node(const string& s = "")
	{
		this->name = s;
		scores = 0;
		MEM(cnt, 0);
	}
};
vector<Node> vs;
map<string, int>mc;
bool cmp1(const Node& node1, const Node& node2)
{
	if (node1.scores != node2.scores) return node1.scores > node2.scores;
	for (int i = 0; i < 50; i++)
	{
		if (node1.cnt[i] != node2.cnt[i])
			return node1.cnt[i] > node2.cnt[i];
	}
	return false;
}

bool cmp2(const Node& node1, const Node& node2)
{
	if (node1.cnt[0] != node2.cnt[0]) return node1.cnt[0] > node2.cnt[0];
	if (node1.scores != node2.scores) return node1.scores > node2.scores;
	for (int i = 1; i < 50; i++)
	{
		if (node1.cnt[i] != node2.cnt[i])
			return node1.cnt[i] > node2.cnt[i];
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	while (n--)
	{
		int sz;
		cin >> sz;
		for (int i = 0; i < sz; i++)
		{
			string str;
			cin >> str;
			if (!mc.count(str))
			{
				mc[str] = vs.size();
				vs.push_back(Node(str));
			}
			auto& node = vs[mc[str]];
			node.scores += a[i];
			node.cnt[i]++;
		}
	}
	sort(vs.begin(), vs.end(), cmp1);
	cout << vs[0].name << endl;
	sort(vs.begin(), vs.end(), cmp2);
	cout << vs[0].name << endl;
	return 0;
}