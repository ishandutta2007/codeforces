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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e4 + 10;
const int M = 4e5 + 10;
int cnt1[N];
int cnt2[N];
char str[M];
char* p[M];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		map<int, int> mc;
		while (n--)
		{
			int x;
			scanf("%d", &x);
			mc[x]++;
		}
		vector<int> v;
		for (auto& p : mc)
			v.push_back(p.second);
		sort(v.rbegin(), v.rend());
		int ans = 0;
		int cur = INF;
		for (auto& x : v)
		{
			cur = min(cur, x);
			ans += max(0, cur--);
		}
		printf("%d\n", ans);
	}
	return 0;
}