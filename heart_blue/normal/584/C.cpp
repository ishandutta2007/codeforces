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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;

char check(char c1, char c2)
{
	for (int i = 'a'; i <= 'z'; i++)
	{
		if (i != c1 && i != c2) return i;
	}
	return 'a';
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int dif = 0, same = 0;
	int n, t;
	cin >> n >> t;
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < n; i++)
	{
		if (s1[i] == s2[i]) same++;
		else dif++;
	}
	int k = -1;
	int o = 0;
	for (int i = dif & 1; i <= dif; i += 2)
	{
		int x = i + (dif - i) / 2;
		if (x > t) continue;
		if (x + same >= t)
		{
			k = i;
			o = t - x;
			break;
		}
	}
	if (k == -1)
	{
		cout << -1 << endl;
		return 0;
	}
	int l = (dif - k) / 2;
	int r = l;
	string ans = s1;
	for (int i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			if (k-- > 0) ans[i] = check(s1[i], s2[i]);
			else if (l-- > 0) ans[i] = s1[i];
			else if (r-- > 0) ans[i] = s2[i];
		}
		else
		{
			if (o-- > 0) ans[i] = check(s1[i], s2[i]);
		}
	}
	cout << ans << endl;
	return 0;
}