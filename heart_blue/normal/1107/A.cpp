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
const int N = 1e3 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		string str;
		cin >> n >> str;
		if (n == 2)
		{
			if (str[0] >= str[1]) cout << "NO" << '\n';
			else cout << "YES\n2\n" << str[0] << ' ' << str[1] << endl;
		}
		else
		{
			cout << "YES\n2\n";
			cout << str[0] << ' ' << str.substr(1) << endl;
		}
	}
	return 0;
}