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
const int N = 1e5 + 10;
int a[N];
class Node
{
public:
	char ch;
	int cnt1, cnt2;
	int pos;
	Node(char ch = 0, int cnt1 = 0, int cnt2 = 0, int pos = -1)
	{
		this->ch = ch;
		this->cnt1 = cnt1;
		this->cnt2 = cnt2;
		this->pos = pos;
	}
	bool operator < (const Node &node) const
	{
		return cnt1 < node.cnt1;
	}
};
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	a['['] = ']';
	a['('] = ')';
	a['{'] = '}';
	string str;
	cin >> str;
	Node ans;
	vector<Node> s;
	Node dump('{');
	s.push_back(dump);
	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (a[c])
		{
			s.push_back(Node(c, 0, 0, i));
			continue;
		}
		if (a[s.back().ch] != c)
		{
			s.clear();
			s.push_back(Node('{', 0, 0, i));
			continue;
		}
		int cnt1 = s.back().cnt1 + (c == ']'), cnt2 = s.back().cnt2 + 1;
		s.pop_back();
		s.back().cnt1 += cnt1;
		s.back().cnt2 += cnt2;
		ans = max(ans, s.back());
	}
	cout << ans.cnt1 << endl;
	cout << str.substr(ans.pos + 1, ans.cnt2 * 2) << endl;

	return 0;
}