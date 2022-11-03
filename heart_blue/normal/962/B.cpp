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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b;
	cin >> n >> a >> b;
	string str;
	cin >> str;
	str += '*';
	int cnt = 0;
	int ans = 0;
	for (auto &c : str)
	{
		if (c == '.') cnt++;
		else
		{
			if (a < b) swap(a, b);
			while (cnt--)
			{
				if (a-- > 0) ans++;
				swap(a, b);
			}
			cnt = 0;
		}
	}
	cout << ans << endl;
	return 0;
}