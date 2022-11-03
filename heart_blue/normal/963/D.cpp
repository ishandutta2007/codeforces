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
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
char s[N][26];
int n;//times
vector<int> vv[N];
struct aho_corasick {
	const static int max_ch = 26;
	int next[N][max_ch], fail[N];
	int mark[N];
	int root, L;
	int newnode() {
		for (int j = 0; j < 26; j++) next[L][j] = -1;
		mark[L] = 0;
		return L++;
	}
	void init() {
		L = 0;
		root = newnode();
	}
	void insert(string &buf, int id) {
		int len = buf.length();
		int now = root;
		for (int j = 0; j < len; j++) {
			if (next[now][buf[j] - 'a'] == -1) next[now][buf[j] - 'a'] = newnode();
			now = next[now][buf[j] - 'a'];
		}
		mark[now] = id;
	}
	void build() {
		queue<int>Q;
		fail[root] = root;
		for (int j = 0; j < max_ch; j++) {
			if (next[root][j] == -1) next[root][j] = root;
			else {
				fail[next[root][j]] = root;
				Q.push(next[root][j]);
			}
		}
		while (!Q.empty()) {
			int now = Q.front();
			if (mark[fail[now]]) mark[now] = 1;
			Q.pop();
			for (int j = 0; j < max_ch; j++) {
				if (next[now][j] == -1) next[now][j] = next[fail[now]][j];
				else {
					fail[next[now][j]] = next[fail[now]][j];
					Q.push(next[now][j]);
				}
			}
		}
	}
	void query(string &s) {
		int n = s.length();
		int now = root;
		for (int j = 0; j < n; j++) {
			now = next[now][s[j] - 'a'];
			if (mark[now]) {
				//                printf("mark = %d\n",mark[now]);
				int id = mark[now];
				vv[mark[now]].push_back(j);
			}
		}
	}
} AC;
string vs[N];
int v[N];
int flag[N];
int ans[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	std::ios::sync_with_stdio(false);
	string str;
	cin >> str;
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		cin >> v[i] >> vs[i];
	}
	MEM(flag, 0);
	while (1)
	{
		AC.init();
		int cur = -1;
		for (int i = 1; i <= q; i++)
		{
			int len = vs[i].length();
			if (flag[i]) continue;
			if (cur == -1) cur = len;
			if (vs[i].length() == cur)
			{
				flag[i] = 1;
				AC.insert(vs[i], i);
			}
		}
		if (cur == -1) break;
		AC.build();
		AC.query(str);
	}
	for (int i = 1; i <= q; i++)
	{
		if (vv[i].size() < v[i])
		{
			cout << -1 << '\n';
		}
		else
		{
			int ans = INF;
			for (int o = v[i] - 1; o < vv[i].size(); o++)
			{
				ans = min(ans, int(vv[i][o] - (vv[i][o - v[i] + 1] - vs[i].length() + 1) + 1));
			}
			cout << ans << '\n';
		}
	}
	return 0;
}