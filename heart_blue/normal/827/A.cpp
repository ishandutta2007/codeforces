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
vector<int> v[N];
typedef pair<int, int> Node;
priority_queue<Node, vector<Node>, greater<Node>> pq;
char str[N * 100];
vector<string> vs;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int len = 0;
	MEM(str, 'a');
	cin >> n;
	vs.push_back("");
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		vs.push_back(str);
		int k;
		cin >> k;
		v[i].resize(k);
		for (auto &x : v[i]) cin >> x;
		len = max(len, (int)(v[i].back() + str.length()));
		reverse(v[i].begin(), v[i].end());
		pq.push({ v[i].back(),i });
		v[i].pop_back();
	}
	str[len] = 0;
	int cur = 1;
	while (!pq.empty())
	{
		int o, idx;
		tie(o, idx) = pq.top();
		pq.pop();
		if (v[idx].size())
		{
			pq.push({ v[idx].back(),idx });
			v[idx].pop_back();
		}
		if (o + vs[idx].length() >= cur)
		{
			int p = o + vs[idx].length() - cur;
			p = vs[idx].length() - p;
			if (p < 0) cur -= p, p = 0;
			while (p < vs[idx].length()) 
				str[cur++] = vs[idx][p++];
		}
	}
	puts(str + 1);

	return 0;
}