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
const int N = 2e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		vector<string> vs = { "RGB","GBR","BRG" };
		int n, k;
		string str;
		cin >> n >> k >> str;
		int ans = INF;
		for (auto& s : vs)
		{
			int sum = 0;
			for (int i = 0; i < str.length(); i++)
			{
				sum += str[i] != s[i % 3];
				if (i >= k) sum -= str[i - k] != s[(i - k) % 3];
				if (i + 1 >= k) ans = min(ans, sum);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}