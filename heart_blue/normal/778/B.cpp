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
const int N = 5e3 + 10;
map<string, int> ms;
vector<string> vs;
int a[N];
class Node
{
public:
	string param, dump, s1, op, s2;
	int x, y;
	void init(string &str, int i)
	{
		stringstream sin(str);
		sin >> param >> dump >> s1 >> op >> s2;
		ms[param] = i;
		if (!op.empty())
		{
			x = ms[s1];
			y = ms[s2];
		}
	}
	int getnum(int pos)
	{
		if (op.empty()) return s1[pos] - '0';
		else
		{
			if (op == "XOR") return a[x] ^ a[y];
			else if (op == "OR") return a[x] | a[y];
			else return a[x] & a[y];
		}
	}
};
vector<Node> v;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	string str;
	getline(cin, str);
	vs.push_back("?");
	ms["?"] = 0;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		getline(cin, str);
		v[i].init(str, i);
	}
	string ans1(m, '0'), ans2(m, '0');
	for (int i = 0; i < m; i++)
	{
		int cnt0 = 0;
		a[0] = 0;
		for (int j = 1; j <= n; j++)
		{
			a[j] = v[j].getnum(i);
			cnt0 += a[j];
		}
		int cnt1 = 0;
		a[0] = 1;
		for (int j = 1; j <= n; j++)
		{
			a[j] = v[j].getnum(i);
			cnt1 += a[j];
		}
		if (cnt0 > cnt1) ans1[i] = '1';
		else if (cnt0 < cnt1) ans2[i] = '1';
	}
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
}