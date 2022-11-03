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
const int N = 1e2 + 10;
int cnt[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int cur = 0;
	while (n--)
	{
		int x;
		cin >> x;
		int cost = cur + x - m;
		int ans = 0;
		for (int i = 100; i > 0; i--)
		{
			if (cost <= 0) break;
			int o = (cost + i - 1) / i;
			o = min(cnt[i], o);
			ans += o;
			cost -= o * i;
		}
		cnt[x]++;
		cur += x;
		printf("%d ", ans);
	}
	return 0;
}