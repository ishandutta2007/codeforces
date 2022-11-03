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
const int N = 2e5 + 10;
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, q;
		scanf("%d%d", &n, &q);
		scanf("%s", str + 1);
		while (q--)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			vector<int> v1, v2;
			int ptr = 1;
			for (int i = l; i <= r; i++)
			{
				while (str[ptr] != str[i])
					ptr++;
				v1.push_back(ptr);
				ptr++;
			}
			ptr = n;
			for (int i = r; i >= l; i--)
			{
				while (str[ptr] != str[i])
					ptr--;
				v2.push_back(ptr);
				ptr--;
			}
			reverse(v2.begin(), v2.end());
			if (v1 == v2) puts("NO");
			else puts("YES");
		}
	}
	return 0;
}