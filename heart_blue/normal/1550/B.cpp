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
#include <chrono>
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
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, a, b;
		scanf("%d%d%d", &n, &a, &b);
		int cnt = 0;
		string str;
		cin >> str;
		for (int i = 1; i < str.length(); i++)
		{
			cnt += str[i] ^ str[i - 1];
		}
		cnt++;
		int ans = 0;
		if (b > 0) ans = (b + a) * n;
		else ans = a * n + (cnt + 2) / 2 * b;
		printf("%d\n", ans);
	}
	return 0;
}