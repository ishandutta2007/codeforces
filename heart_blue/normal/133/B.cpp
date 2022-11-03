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
const int N = 2e2 + 10;

int a[N];
void init()
{
	a['>'] = 0b1000;
	a['<'] = 0b1001;
	a['+'] = 0b1010;
	a['-'] = 0b1011;
	a['.'] = 0b1100;
	a[','] = 0b1101;
	a['['] = 0b1110;
	a[']'] = 0b1111;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int mod = 1000003;
	string str;
	cin >> str;
	LL ans = 0;
	init();
	for (auto &c : str)
	{
		ans <<= 4;
		ans = (ans+a[c]) % mod;
	}
	cout << ans << endl;
	return 0;
}