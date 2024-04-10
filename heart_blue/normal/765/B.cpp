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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	map<int, int> m;
	int maxv = 0;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		m[s[i]] = i;
		maxv = max(maxv, s[i] - 'a');
	}
	if (maxv + 1 != m.size())
	{
		cout << "NO" << endl;
		return 0;
	}
	vector<int> v;
	for (auto &p : m) v.push_back(p.second);
	int flag = 1;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] < v[i - 1]) flag = 0;
	}
	if (flag) puts("YES");
	else puts("NO");
	return 0;
}