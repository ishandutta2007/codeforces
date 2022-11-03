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
const int N = 2e5 + 10;
char s1[N];
char s2[N];
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
		scanf("%s", s1 + 1);
		scanf("%s", s2 + 1);
		int l = 1, r = n;
		int o1 = 1, o2 = -1;
		vector<int> ans;
		int o = 0;
		for (int i = n; i >= 1; i--)
		{
			if ((s1[r] ^ o) == s2[i])
			{
				r += o2;
				continue;
			}
			if ((s1[l] ^ o) == s2[i]) ans.push_back(1);
			ans.push_back(abs(r - l) + 1);
			swap(l, r);
			swap(o1, o2);
			o ^= 1;
			r += o2;
		}
		printf("%d", ans.size());
		for (auto& x : ans)
			printf(" %d", x);
		puts("");
	}
	return 0;
}