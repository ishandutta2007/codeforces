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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int cnt = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	string str;
	cin >> str;
	str += '0';
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '1') cnt++;
		else
		{
			sort(a + i - cnt, a + i + 1);
			cnt = 0;
		}
	}
	int flag = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != i + 1)
		{
			flag = 0;
		}
	}
	if (flag) puts("YES");
	else puts("NO");
	return 0;
}