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
int cnt[200];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string str;
	cin >> n >> str;
	int avg = n / 3;
	for (auto& c : str) cnt[c]++;
	for (int i = '2'; i >= '0'; i--)
	{
		if (cnt[i] <= avg) continue;
		for (int j = '0'; j < i; j++)
		{
			if (cnt[j] >= avg) continue;
			for (auto& c : str)
			{
				if (c == i && cnt[i] > avg && cnt[j] < avg)
				{
					c = j;
					cnt[i]--;
					cnt[j]++;
				}
			}
		}
	}
	reverse(str.begin(), str.end());
	for (int i = '0'; i <= '2'; i++)
	{
		if (cnt[i] <= avg) continue;
		for (int j = '2'; j > i; j--)
		{
			if (cnt[j] >= avg) continue;
			for (auto& c : str)
			{
				if (c == i && cnt[i] > avg && cnt[j] < avg)
				{
					c = j;
					cnt[i]--;
					cnt[j]++;
				}
			}
		}
	}
	reverse(str.begin(), str.end());
	cout << str << endl;
	return 0;
}