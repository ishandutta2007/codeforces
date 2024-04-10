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
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
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
		vector<int> v(n);
		for (auto& x : v)
			scanf("%d", &x);
		sort(v.rbegin(), v.rend());
		int cur = v[0];
		for (int i = 1; i < v.size(); i++)
		{
			if (cur == 1) break;
			int maxv = 0;
			int id = i;
			for (int j = i; j < v.size(); j++)
			{
				if (gcd(v[j], cur) > maxv)
				{
					maxv = gcd(v[j], cur);
					id = j;
				}
			}
			swap(v[i], v[id]);
			cur = maxv;
		}
		for (int i = 0; i < v.size(); i++)
			printf("%d ", v[i]);
		puts("");
	}
	return 0;
}