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
const int N = 1e4 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, r, b;
		scanf("%d%d%d", &n, &r, &b);
		int cnt = r / (b + 1);
		int x = r % (b + 1);
		int y = b + 1 - x;
		string ans;
		while (x--) ans += string(cnt + 1, 'R') + 'B';
		while (y--) ans += string(cnt, 'R') + 'B';
		ans.pop_back();
		puts(ans.c_str());
	}
	return 0;
}