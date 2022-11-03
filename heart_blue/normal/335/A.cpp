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
const int N = 3e5 + 10;
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	for (auto& c : str)
		cnt[c - 'a']++;
	int n;
	cin >> n;
	string ans;
	for (int i = 1; i <= str.length(); i++)
	{
		int tot = 0;
		for (int o = 0; o < 26; o++)
		{
			tot += (cnt[o] + i - 1) / i;
		}
		if (tot > n) continue;
		cout << i << endl;
		for (int o = 0; o < 26; o++)
		{
			ans += string((cnt[o] + i - 1) / i, o + 'a');
		}
		while (ans.length() < n) ans.push_back('a');
		cout << ans << endl;
		return 0;
	}
	puts("-1");
	return 0;
}