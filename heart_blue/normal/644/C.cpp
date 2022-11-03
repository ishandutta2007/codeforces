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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
map<string, int> ms1, ms2;
vector<string> vs;
map<int, int> v[N];
vector<int> key;
vector<pair<int, int>> ans;
int main()
{
	//freopen("B-large.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string str;
	int n1 = 0, n2 = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		int l = str.length();
		int cnt = 0;
		int idx = 0;
		for (int i = 0; i < l; i++)
		{
			if (str[i] == '/')
			{
				cnt++;
				if (cnt == 3)
				{
					idx = i;
					break;
				}
			}

		}
		if (cnt == 2)
		{
			if (!ms1.count(str))
			{
				ms1[str] = n1++;
			}
			v[ms1[str]][0] = 1;
		}
		else
		{
			string str1 = str.substr(0, idx);
			string str2 = str.substr(idx + 1);
			if (!ms1.count(str1)) ms1[str1] = n1++;
			if (!ms2.count(str2)) ms2[str2] = n2++;
			v[ms1[str1]][ms2[str2]] = 1;
		}

	}
	for (int i = 0; i < n1; i++) key.push_back(i);
	//for (int i = 0; i < n1; i++) sort(v[i].begin(), v[i].end());
	//for (int i = 0; i < n1; i++) unique(v[i].begin(), v[i].end());
	vs.resize(ms1.size());
	for (auto &iter : ms1)
	{
		vs[iter.second] = iter.first;
	}
	sort(key.begin(), key.end(), [](int x, int y) -> bool
	{
		return v[x] < v[y];
	});
	int cur = 0;
	for (int i = 1; i < n1; i++)
	{
		if (v[key[i]] != v[key[cur]])
		{
			if (i - 1 != cur)
			{
				ans.push_back({ cur, i - 1 });
			}
			cur = i;
		}
	}
	if (cur != n1 - 1)
	{
		ans.push_back({ cur, n1 - 1 });
	}
	cout << ans.size() << endl;
	for (auto &iter : ans)
	{
		int x, y;
		tie(x, y) = iter;
		for (int i = x; i <= y; i++)
		{
			cout << vs[key[i]] << ' ';
		}
		cout << endl;
	}

	return 0;
}