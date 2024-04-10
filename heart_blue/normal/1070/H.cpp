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
const int N = 3e5 + 10;

map<string, int> mc;
map<string, string> ms;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		vector<string> vs;
		for (int i = 0; i < str.length(); i++)
		{
			for (int j = 1; i + j <= str.length(); j++)
			{
				vs.emplace_back(str.substr(i, j));
			}
		}
		sort(vs.begin(), vs.end());
		vs.resize(unique(vs.begin(), vs.end()) - vs.begin());
		for (auto& s : vs)
		{
			mc[s]++;
			ms[s] = str;
		}
	}
	cin >> q;
	while (q--)
	{
		string str;
		cin >> str;
		if (!mc.count(str))
		{
			puts("0 -");
			continue;
		}
		else
			printf("%d %s\n", mc[str], ms[str].c_str());
	}
	return 0;
}