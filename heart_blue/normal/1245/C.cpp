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
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int f[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	f[0] = f[1] = 1;
	for (int i = 2; i < N; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		if (f[i] >= INF) f[i] -= INF;
	}
	string str;
	cin >> str;
	str.push_back('#');
	char pre = '1';
	int cnt = 0;
	LL ans = 1;
	for (auto &c : str)
	{
		if (c == 'm' || c == 'w') puts("0"), exit(0);
		if (c == pre) cnt++;
		else
		{
			if (pre == 'n' || pre == 'u')
			{
				ans = ans * f[cnt] % INF;
			}
			pre = c;
			cnt = 1;
		}
	}
	cout << ans << endl;
	return 0;
}