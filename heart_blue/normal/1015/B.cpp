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
const int N = 5e3 + 10;
bool check(string s1, string s2)
{
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	return s1 == s2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;
	vector<int> v;
	if (!check(s1, s2))
	{
		puts("-1");
		return 0;
	}
	vector<int> ans;
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] == s2[i]) continue;
		int j = i;
		while (j < s1.length() && s1[j] != s2[i]) j++;
		while (j > i)
		{
			ans.push_back(j--);
			swap(s1[j], s1[j + 1]);
		}
	}
	cout << ans.size() << endl;
	for (auto &x : ans) cout << x << ' ';
	return 0;
}