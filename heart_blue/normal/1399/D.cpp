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
const int N = 2e2 + 10;
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
		int cnt[2] = { 0,0 };
		vector<int> v[2];
		string str;
		cin >> str;
		int cur = 0;
		vector<int> ans;
		for (auto& c : str)
		{
			int o = c - '0';
			if (cnt[o] == 0)
			{
				v[o].push_back(++cur);
				cnt[o] = 1;
			}
			cnt[o]--;
			cnt[o ^ 1]++;
			ans.push_back(v[o].back());
			v[o ^ 1].push_back(v[o].back());
			v[o].pop_back();
		}
		printf("%d\n", cur);
		for (auto& x : ans)
			printf("%d ", x);
		puts("");
	}
	return 0;
}