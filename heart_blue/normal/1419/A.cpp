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
typedef long long ll;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		string str;
		cin >> n >> str;
		vector<int> v[2];
		for (int i = 0; i < n; i++)
		{
			v[i & 1].push_back(str[i] & 1);
		}
		sort(v[0].rbegin(), v[0].rend());
		sort(v[1].begin(), v[1].end());
		int o = 0;
		while (v[0].size() + v[1].size() > 1)
		{
			v[o].pop_back();
			o ^= 1;
		}
		if (v[0].size() < v[1].size()) swap(v[0], v[1]);
		if (v[0][0] & 1) puts("1");
		else puts("2");
	}
	return 0;
}