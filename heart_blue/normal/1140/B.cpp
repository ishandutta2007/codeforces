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
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		string str;
		cin >> str;
		int o1 = str.find('>');
		int o2 = str.find_last_of('<');
		int ans = INF;
		if (o1 == str.npos || o2 == str.npos) ans = 0;
		if (o1 != str.npos) ans = min(ans, o1);
		if (o2 != str.npos) ans = min(ans, n - o2 - 1);
		cout << ans << endl;
	}
	return 0;
}