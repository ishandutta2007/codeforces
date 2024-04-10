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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	LL ans = 1;
	int cnt = 0;
	string str;
	cin >> str;
	map<char, int> mc;
	for (auto &c : str)
	{
		if (c == '?') cnt++;
		else if (isalpha(c)) mc[c] = 1;
	}
	int o = 10;
	for (auto &p : mc)
	{
		ans *= o--;
	}
	if (str[0] == '?') cnt--, ans *= 9;
	else if (isalpha(str[0])) ans = ans / 10 * 9;
	cout << ans << string(cnt, '0') << endl;
	return 0;
}