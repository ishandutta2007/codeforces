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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<string, int> ms;
	string str;
	int n;
	cin >> n;
	cin >> str;
	for (int i = 0; i + 2 <= str.length(); i++)
	{
		ms[str.substr(i, 2)]++;
	}
	pair<int, string> ans = { -1,"" };
	for (auto &p : ms)
	{
		ans = max(ans, { p.second,p.first });
	}
	cout << ans.second << endl;
		return 0;
}