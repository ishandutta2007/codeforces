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
#include <cassert>
#include <iterator>
#include <complex>
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
	string ans;
	int n;
	cin >> n;
	string str;
	cin >> str;
	reverse(str.begin(), str.end());
	while (str.length() > 1)
	{
		char c1 = str.back();
		while (!str.empty() && str.back() == c1) str.pop_back();
		if (str.empty()) break;
		ans.push_back(c1);
		ans.push_back(str.back());
		str.pop_back();
	}
	cout << n - ans.length() << endl;
	cout << ans << endl;
	return 0;
}