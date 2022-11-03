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
const int N = 3e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		vector<int> v;
		vector<string> vs;
		int n;
		cin >> n;
		int cnt[4];
		MEM(cnt, 0);
		map<string, int> ms;
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			vs.emplace_back(str);
			ms[str] = 1;
			int o = (str.front() - '0') << 1 | (str.back() - '0');
			cnt[o]++;
			v.push_back(o);
		}
		if (cnt[0] > 0 && cnt[3] > 0 && cnt[1] + cnt[2] == 0)
		{
			puts("-1");
			continue;
		}
		vector<int> ans;
		int maxv = (cnt[1] + cnt[2] + 1) / 2;
		for (int i = 0; i < n; i++)
		{
			if (cnt[v[i]] > maxv && (v[i] == 1 || v[i] == 2))
			{
				string& s = vs[i];
				reverse(s.begin(), s.end());
				if (ms.count(s)) continue;
				ans.push_back(i + 1);
				cnt[v[i]]--;
			}
		}
		printf("%d\n", ans.size());
		for (auto& x : ans) printf("%d ", x);
		puts("");
	}
	return 0;
}