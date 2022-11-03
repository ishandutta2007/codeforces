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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<string> vs(n);
	for (auto &str : vs) cin >> str;
	sort(vs.begin(), vs.end(), [](const string &s1, const string &s2) -> bool
	{
		return s1.length() < s2.length();
	});
	for (int i = 1; i < n; i++)
	{
		if (vs[i].find(vs[i - 1]) == string::npos)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for (auto &str : vs) cout << str << endl;
	return 0;
}