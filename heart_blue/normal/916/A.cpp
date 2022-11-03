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
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 0; i < 100; i++)
	{
		if (i % 10 == 7 || i / 10 == 7) flag[i] = 1;
	}
	int x;
	cin >> x;
	int h, m;
	cin >> h >> m;
	int cur = h * 60 + m;
	int ans = 0;
	while (flag[cur / 60] == 0 && flag[cur % 60] == 0)
	{
		ans++;
		cur -= x;
		if (cur < 0) cur += 24 * 60;
	}
	cout << ans << endl;
	return 0;
}