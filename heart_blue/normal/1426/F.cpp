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
const int N = 5e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL cnt[4] = { 1LL,0LL,0LL,0LL };
	LL pre[4];
	scanf("%*d");
	string str;
	cin >> str;
	for (auto& c : str)
	{
		memcpy(pre, cnt, sizeof(pre));
		MEM(cnt, 0);
		for (int i = 2; i >= 0; i--)
		{
			if (i + 'a' == c || c == '?')
			{
				cnt[i + 1] = pre[i];
			}
		}
		LL o = 1;
		if (c == '?')
			o = 3;
		for (int i = 0; i <= 3; i++)
		{
			cnt[i] = (cnt[i] + pre[i] * o) % INF;
		}
	}
	printf("%lld\n", cnt[3]);

	return 0;
}