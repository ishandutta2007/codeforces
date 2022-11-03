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
map<string, int> ms;
vector<pair<int, string>> vp;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string o;
	cin >> o;
	ms[o] = 0;
	int n;
	cin >> n;
	while (n--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		if (s2 == "posted")
		{
			string dump;
			cin >> dump >> s2;
			s2.pop_back(), s2.pop_back();
			ms[s1], ms[s2];
			if (s1 != o && s2 != o) goto hehe;
			ms[s1] += 15, ms[s2] += 15;
		}
		else if (s2 == "commented")
		{
			string dump;
			cin >> dump >> s2;
			s2.pop_back(), s2.pop_back();
			ms[s1], ms[s2];
			if (s1 != o && s2 != o) goto hehe;
			ms[s1] += 10, ms[s2] += 10;
		}
		else
		{
			cin >> s2;
			s2.pop_back(), s2.pop_back();
			ms[s1], ms[s2];
			if (s1 != o && s2 != o) goto hehe;
			ms[s1] += 5, ms[s2] += 5;
		}
		hehe:
		getline(cin, s1);
	}
	for (auto &p : ms)
	{ 
		if (p.first == o) continue;
		vp.push_back({ p.second, p.first });
	}
	sort(vp.begin(), vp.end(), [](pair<int, string>&p1, pair<int, string>&p2)->bool
	{
		if (p1.first != p2.first) return p1.first > p2.first;
		else return p1.second < p2.second;
	});
	for (auto &p : vp) cout << p.second << endl;
	return 0;
}