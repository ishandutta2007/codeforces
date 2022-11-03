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
const int N = 5e5 + 20;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		map<int, int> mc;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			mc[x]++;
		}
		vector<int> v;
		for (auto& p : mc)
			v.push_back(p.second);
		reverse(v.begin(), v.end());
		int tot = n;
		while (!v.empty() && tot * 2 > n)
		{
			tot -= v.back();
			v.pop_back();
		}
		if (v.size() < 3)
		{
			puts("0 0 0 ");
			continue;
		}
		int s = 0;
		for (int i = 1; i < v.size(); i++)
		{
			s += v[i];
			if (s > v[0]) break;
		}
		if (v[0] >= tot - s - v[0]) puts("0 0 0");
		else printf("%d %d %d\n", v[0], s, tot - s - v[0]);
	}
	return 0;
}