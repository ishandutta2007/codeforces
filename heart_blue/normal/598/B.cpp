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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	string str;
	cin >> str;
	int q;
	cin >> q;
	while (q--)
	{
		int l, r, k;
		cin >> l >> r >> k;
		l--, r--;
		int len = (r - l + 1);
		k %= len;
		string s = str.substr(l, len);
		s =  s.substr(len - k) + s.substr(0, len - k);
		str = str.substr(0, l) + s + str.substr(r + 1);
	}
	cout << str << endl;
	return 0;
}