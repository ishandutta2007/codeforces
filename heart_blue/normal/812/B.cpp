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
	int n, m;
	vector<string> vs;
	cin >> n >> m;
	string s = string(m + 2, '0');
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (s == str && vs.empty()) continue;
		vs.push_back(str);
	}
	reverse(vs.begin(), vs.end());
	int l = 0, r = INF;
	int ans = 0;
	for (auto &str : vs)
	{
		ans = INF;
		if (str == s)
		{
			l++, r++;
			l = min(l, r + m + 1);
			r = min(r, l + m + 1);
			continue;
		}
		ans = min(ans, l + (int)str.find_last_of('1'));
		ans = min(ans, r + m + 1 - (int)str.find_first_of('1'));
		int L = min(l + 2*(int)str.find_last_of('1'),r+m+1);
		int R = min(r + 2 * (m + 1 - (int)str.find_first_of('1')), l + m + 1);
		L++, R++;
		l = L;
		r = R;
	}
	cout << ans << endl;

	return 0;
}