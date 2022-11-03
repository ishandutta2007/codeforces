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
	LL c, h1, h2, w1, w2;
	cin >> c >> h1 >> h2 >> w1 >> w2;
	LL ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (i*w1 > c) break;
		ans = max(ans, i*h1 + (c - w1*i) / w2*h2);
	}
	for (int i = 0; i < N; i++)
	{
		if (i*w2 > c) break;
		ans = max(ans, i*h2 + (c - w2*i) / w1*h1);
	}
	cout << ans << endl;
	return 0;
}