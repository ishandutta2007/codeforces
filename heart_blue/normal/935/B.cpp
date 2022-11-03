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
const int N = 5e3 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int pre = 0;
	string str;
	int n;
	cin >> n;
	cin >> str;
	int cur = 0;
	int ans = 0;
	for (auto &c : str)
	{
		int o = 0;
		if (c == 'U') o = cur + 1;
		else o = cur - 1;
		if (cur == 0)
		{
			if (o*pre == -1) ans++;
			pre = o;
		}
		cur = o;
	}
	cout << ans << endl;
	return 0;
}