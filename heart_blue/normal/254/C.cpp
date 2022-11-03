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
const int N = 2e2 + 10;
int cnt1[N];
int cnt2[N];
int rest[N];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string s1, s2;
	cin >> s1 >> s2;
	for (auto& c : s1) cnt1[c]++;
	for (auto& c : s2) cnt2[c]++;
	memcpy(rest, cnt1, sizeof(rest));
	int ans = 0;
	for (auto& c : s1)
	{
		if (cnt1[c] <= cnt2[c]) continue;
		char maxv = c - 1;
		if (cnt1[c] - cnt2[c] == rest[c]) maxv = 'Z';
		rest[c]--;
		for (int i = 'A'; i <= maxv; i++)
		{
			if (cnt1[i] < cnt2[i])
			{
				ans++;
				cnt1[c]--;
				cnt1[i]++;
				c = i;
				break;
			}
		}
	}

	cout << ans << endl;
	cout << s1 << endl;
	return 0;
}