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
LL sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	for (int i = 1; i < N; i++)
		sum[i] = 1LL * i * (i - 1) / 2;
	while (ncase--)
	{
		vector<int> ans;
		int n;
		scanf("%d", &n);
		putchar('1');
		for (int i = 1e5; i > 1; i--)
		{
			while (n >= sum[i])
			{
				ans.push_back(i);
				n -= sum[i];
			}
		}
		int tot = 0;
		while (!ans.empty())
		{
			while (tot < ans.back()) tot++, putchar('3');
			putchar('7');
			ans.pop_back();
		}
		puts("");
	}
	return 0;
}