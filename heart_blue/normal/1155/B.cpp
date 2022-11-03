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
int a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string str;
	cin >> str;
	int rest = (n - 11) / 2;
	string s;
	for (int i = 0; i < n; i++)
	{
		if (str[i] != '8' && rest > 0)
		{
			rest--;
			continue;
		}
		s.push_back(str[i]);
	}
	int cnt = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '8') cnt++;
		else break;
	}
	if (cnt > (n - 11) / 2) puts("YES");
	else puts("NO");
	return 0;
}