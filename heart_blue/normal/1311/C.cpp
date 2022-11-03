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
const int N = 2e5 + 10;
int cnt[200];
LL ans[200];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		cin >> n >> m;
		MEM(ans, 0);
		scanf("%s", str + 1);
		vector<int> v(m);
		for (auto& x : v) scanf("%d", &x);
		int ptr = 1;
		MEM(cnt, 0);
		sort(v.begin(), v.end());
		v.push_back(n);
		for (auto& x : v)
		{
			while (ptr <= x)
			{
				cnt[str[ptr]]++;
				ptr++;
			}
			for (int i = 'a'; i <= 'z'; i++)
				ans[i] += cnt[i];
		}
		for (int i = 'a'; i <= 'z'; i++)
			printf("%lld%c", ans[i], " \n"[i == 'z']);
	}
	return 0;
}