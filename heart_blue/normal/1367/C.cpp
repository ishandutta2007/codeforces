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
const LL INF = 1e9 + 9;
const int N = 2e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		cin >> n >> k;
		string str;
		cin >> str;
		int cur = 0;
		int ans = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '0') continue;
			while (cur + k < i)
			{
				ans++;
				cur += k + 1;
			}
			cur = i + k + 1;
		}
		while (cur < n)
		{
			ans++;
			cur += k + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}