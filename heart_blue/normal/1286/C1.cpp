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
const int N = 2e3 + 10;
vector<string> vs1[N],vs2[N];
int sub(string& s1, string& s2)
{
	map<char, int> mc;
	for (auto& c : s1) mc[c]++;
	for (auto& c : s2) mc[c]--;
	char key = 0;
	for (auto& p : mc)
	{
		if (p.second)
		{
			key = p.first;
		}
	}
	return key;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	cout << "? 1 " << n << endl;
	int cnt = n * (n + 1) / 2;
	while (cnt--)
	{
		string s;
		cin >> s;
		if (n == 1)
		{
			cout << "! " << s << endl;
			return 0;
		}
		sort(s.begin(), s.end());
		vs1[s.length()].push_back(s);
	}
	cout << "? 2 " << n << endl;
	cnt = n * (n - 1) / 2;
	while (cnt--)
	{
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		vs2[s.length()].push_back(s);
	}
	string ans;
	for (int i = 1; i <= n; i++)
	{
		map<string, int> ms;
		for (auto& s : vs1[i]) ms[s]++;
		for (auto& s : vs2[i]) ms[s]--;
		map<char, int> mc;
		string str;
		for (auto& p : ms)
		{
			if (p.second)
			{
				for (auto& c : p.first) mc[c]++;
			}
		}
		for (auto& c : ans) mc[c]--;
		for (auto& p : mc)
		{
			if (p.second)
			{
				ans.push_back(p.first);
			}
		}
	}
	cout << "! " << ans << endl;
	return 0;
}