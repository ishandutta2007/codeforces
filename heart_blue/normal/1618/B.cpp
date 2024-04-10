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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		cin >> n;
		vector<string> vs(n - 2);
		for (auto& s : vs)
			cin >> s;
		string ans = vs[0];
		int flag = 0;
		for (int i = 1; i < vs.size(); i++)
		{
			if (ans.back() != vs[i].front())
			{
				ans.push_back(vs[i].front());
				flag = 1;
			}
			ans.push_back(vs[i].back());
		}
		if (!flag)
			ans.push_back(ans.back());
		puts(ans.c_str());
	}
	return 0;
}