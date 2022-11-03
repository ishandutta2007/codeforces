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
const int N = 2e5 + 30;
LL cnt[200][200];
int tot[N];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int cur = 1;
	int n;
	cin >> n;
	n++;
	int d = 1;
	vector<pair<int,int>> ans;
	while (n > 8)
	{
		vector<int> v;
		v.push_back(cur);
		for (int i = 1; i <= 8; i++)
		{
			if (i == cur) continue;
			v.push_back(i);
		}
		while (1)
		{
			random_shuffle(v.begin() + 1, v.end());
			if (v.back() != 8)
				break;
		}
		n -= 8;
		if (n == 1)
		{
			for (auto& x : v)
			{
				if (x == 8)
				{
					swap(x, v.back());
					break;
				}
			}
		}
		for (auto& x : v)
			ans.emplace_back(d, x);
		d++;
		cur = v.back();
	}
	if (ans.empty() || ans.front() != make_pair(1, 1))
		ans.insert(ans.begin(), make_pair(1, 1)), n--;
	ans.emplace_back(8, cur);
	n--;
	for (int i = 1; i < 8; i++)
	{
		if (i == cur) continue;
		if (n <= 1) break;
		n--;
		ans.emplace_back(8, i);
	}
	if(n > 0) ans.emplace_back(8, 8);
	for (auto& p : ans)
	{
		printf("%c%d ", (p.first + 'a' - 1), p.second);
	}
	return 0;
}