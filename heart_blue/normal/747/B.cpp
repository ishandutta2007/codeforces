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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string str;
	cin >> str;
	string acgt = "ACGT";
	MEM(cnt, 0);
	if (n % 4 != 0)
	{
		cout << "===" << endl;
		return 0;
	}
	int maxv = 0;
	for (auto &c : str)
	{
		if (isalpha(c)) cnt[c]++;
		maxv = max(maxv, cnt[c]);
	}
	if (maxv > n / 4)
	{
		cout << "===" << endl;
		return 0;
	}
	for (auto &c1 : str)
	{
		if (c1 != '?') continue;
		for (auto &c2 : acgt)
		{
			if (cnt[c2] < n / 4)
			{
				cnt[c2]++;
				c1 = c2;
				break;
			}
		}
	}
	cout << str << endl;
	return 0;
}