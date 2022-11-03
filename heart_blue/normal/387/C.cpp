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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int nex[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int n = str.length();
	for (int i = n - 1; i >= 0; i--)
	{
		if (i < n - 1 && str[i + 1] == '0') nex[i] = nex[i + 1];
		else nex[i] = i;
	}
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		if (nex[i] - i < i - 1|| (nex[i] - i == i - 1 && str[nex[i] - 2 * i + 1] >= str[i])) ans++;
		else ans = 1;
		i = nex[i];
	}
	cout << ans << endl;
	return 0;
}