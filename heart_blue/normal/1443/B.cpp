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
const int N = 2e3 + 10;
void refrain(string& str)
{
	while (!str.empty() && str.back() == '0') str.pop_back();
	reverse(str.begin(), str.end());
	while (!str.empty() && str.back() == '0') str.pop_back();
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		string str;
		cin >> str;
		refrain(str);
		if (str.empty())
		{
			puts("0");
			continue;
		}
		int cnt = 0;
		vector<int> v;
		for (auto& c : str)
		{
			if (c == '0') cnt++;
			else
			{
				if (cnt) v.push_back(cnt);
				cnt = 0;
			}
		}
		int tot = v.size() + 1;
		int ans = tot * a;
		sort(v.begin(), v.end());
		int sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			sum += v[i];
			ans = min(ans, (tot - i - 1) * a + sum * b);
		}
		printf("%d\n", ans);
	}
	return 0;
}