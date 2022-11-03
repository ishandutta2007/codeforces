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
const int N = 1e6 + 10;
vector<int> v[5];
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
		for (int i = 0; i < 5; i++) v[i].clear();
		while (n--)
		{
			string str;
			cin >> str;
			for (int i = 0; i < 5; i++)
			{
				char c = i + 'a';
				v[i].push_back(2 * count(str.begin(), str.end(), c) - str.length());
			}
		}
		int ans = 0;
		for (int i = 0; i < 5; i++)
		{
			sort(v[i].rbegin(), v[i].rend());
			int sum = 0;
			for (int j = 0; j < v[i].size(); j++)
			{
				sum += v[i][j];
				if (sum <= 0) break;
				ans = max(ans, j + 1);
			}
		}
		printf("%d\n", ans);

	}
	return 0;
}