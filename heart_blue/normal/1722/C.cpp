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
const int N = 1e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		vector<string> vs[3];
		int n;
		scanf("%d", &n);
		map<string, int> ms;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < n; j++)
			{
				string s;
				cin >> s;
				vs[i].push_back(s);
				ms[s]++;
			}
		}
		int a[] = { 0,3,1,0 };
		for (int i = 0; i < 3; i++)
		{
			int sum = 0;
			for (auto& s : vs[i])
			{
				sum += a[ms[s]];
			}
			printf("%d%c", sum, " \n"[i == 2]);
		}
	}
	return 0;
}