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
const int N = 4e3 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		string str;
		cin >> n >> k >> str;
		string ans;
		int rest = n;
		while (k--)
		{
			if (k > 0) ans += "()";
			else ans += string((n - ans.length()) / 2, '(') + string((n - ans.length()) / 2, ')');
		}
		vector<pair<int,int>> v;
		for (int i = 0; i < n; i++)
		{
			if (str[i] != ans[i])
			{
				for (int j = i; j < n; j++)
				{
					if (ans[i] == str[j])
					{
						v.emplace_back(i + 1, j + 1);
						int l = i, r = j;
						while (l < r)
						{
							swap(str[l++], str[r--]);
						}
						break;
					}
				}
			}
		}
		printf("%d\n", v.size());
		for (auto& p : v)
			printf("%d %d\n", p.first, p.second);

	}
	return 0;
}