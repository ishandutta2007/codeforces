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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	if (str.length() & 1) reverse(str.begin(), str.end());
	string ans;
	int l = 0, r = str.length() - 1;
	while (l < r)
	{
		ans.push_back(str[r--]);
		ans.push_back(str[l++]);
	}
	if (str.length() & 1) ans.push_back(str[str.length() / 2]);
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}