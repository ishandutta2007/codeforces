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
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
LL cnt1[N];
LL cnt2[N];
LL tot1 = 0, tot2 = 0;
bool check()
{
	for (int i = 'a'; i <= 'z'; i++)
	{
		if (cnt1[i] == 0) continue;
		for (int j = i + 1; j <= 'z'; j++)
		{
			if (cnt2[j]) return true;
		}
	}
	for (int i = 'a'; i <= 'z'; i++)
	{
		if (cnt1[i] && cnt2[i] && tot1 == cnt1[i])
		{
			if (cnt1[i] < cnt2[i]) return true;
			if (cnt1[i] == cnt2[i] && tot2 != cnt2[i]) return true;
		}
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		tot1 = 1;
		tot2 = 1;
		MEM(cnt1, 0);
		MEM(cnt2, 0);
		cnt1['a'] = 1;
		cnt2['a'] = 1;
		int q;
		scanf("%d", &q);
		while (q--)
		{
			int op, k;
			scanf("%d%d", &op, &k);
			string s;
			cin >> s;
			LL* p = cnt1;
			if (op == 2) p = cnt2, tot2 += 1LL * k * s.length();
			else tot1 += 1LL * k * s.length();
			for (auto& c : s)
				p[c] += k;
			if (check()) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}