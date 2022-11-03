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
const int N = 1e5 + 10;

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
		vector<int> v1, v2;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (i & 1) v1.push_back(x);
			else v2.push_back(x);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		vector<int> v;
		for (int i = 0; i < v2.size(); i++)
		{
			v.push_back(v1[i]);
			v.push_back(v2[i]);
		}
		if (n & 1) v.push_back(v1.back());
		if (is_sorted(v.begin(), v.end()))
			puts("YES");
		else 
			puts("NO");
	}
	return 0;
}