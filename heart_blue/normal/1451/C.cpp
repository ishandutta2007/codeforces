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
const int N = 3e5 + 10;
int cnt1[30];
int cnt2[30];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, k;
		cin >> n >> k;
		string s1, s2;
		cin >> s1 >> s2;
		MEM(cnt1, 0);
		MEM(cnt2, 0);
		for (auto& c : s1) cnt1[c - 'a']++;
		for (auto& c : s2) cnt2[c - 'a']++;
		for (int i = 0; i < 25; i++)
		{
			while (cnt1[i] > cnt2[i] && cnt1[i] >= k)
			{
				cnt1[i] -= k;
				cnt1[i + 1] += k;
			}
		}
		int flag = 1;
		for (int i = 0; i < 26; i++)
		{
			if (cnt1[i] != cnt2[i])
				flag = 0;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}