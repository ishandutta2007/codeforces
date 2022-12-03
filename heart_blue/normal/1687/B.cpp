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
const int N = 2e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> vp;
	for (int i = 0; i < m; i++)
	{
		string str(m, '0');
		str[i] = '1';
		cout << "? " << str << endl;
		int x;
		cin >> x;
		vp.emplace_back(x, i);
	}
	sort(vp.begin(), vp.end());
	int cur = 0;
	string key(m, '0');
	for (auto [w, id] : vp)
	{
		key[id] = '1';
		cout << "? " << key << endl;
		int x;
		cin >> x;
		if (cur + w != x)
		{
			key[id] = '0';
		}
		else
			cur = x;
	}
	cout << "! " << cur << endl;
	return 0;
}