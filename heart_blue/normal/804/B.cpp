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
const int N = 1e6 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	a[0] = 0;
	for (int i = 1; i < N; i++)
	{
		a[i] = (a[i - 1] * 2 + 1) % INF;
	}
	string str;
	cin >> str;
	LL ans = 0;
	int cnt = 0;
	for (auto &c : str)
	{
		if (c == 'a') cnt++;
		else ans = (ans + a[cnt]) % INF;
	}
	cout << ans << endl;
	return 0;
}