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
const int N = 1e8 + 10;

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
		vector<int> v;
		int cnt = 0;
		while (n--)
		{
			int x;
			cin >> x;
			v.push_back(x);
			cnt += x & 1;
		}
		if (cnt % 2 == 0)
		{
			puts("YES");
			continue;
		}
		int flag = INF;
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());
		for (int i = 1; i < v.size(); i++)
		{
			flag = min(flag, v[i] - v[i - 1]);
		}
		if (flag == 1) puts("YES");
		else puts("NO");
	}
	return 0;
}