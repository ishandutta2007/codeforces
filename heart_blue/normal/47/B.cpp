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
const int N = 2e2 + 10;
vector<int> v[N];
int deg[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	int o = 3;
	while (o--)
	{
		cin >> str;
		char c1 = str[0] - 'A';
		char c2 = str[2] - 'A';
		if (str[1] == '>') v[c2].push_back(c1), deg[c1]++;
		else v[c1].push_back(c2), deg[c2]++;
	}
	queue<int> q;
	for (int i = 0; i < 3; i++) if (deg[i] == 0) q.push(i);
	string ans;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		ans.push_back(x + 'A');
		for (auto &y : v[x])
		{
			deg[y]--;
			if (deg[y] == 0) q.push(y);
		}
	}
	if (ans.length() != 3) ans = "Impossible";
	cout << ans << endl;
	return 0;
}