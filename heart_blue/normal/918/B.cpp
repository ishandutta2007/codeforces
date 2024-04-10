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
const int N = 5e3 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	map<string, string> ms;
	cin >> n >> m;
	while (n--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		ms[s2 + ';'] = s1;
	}
	while (m--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		cout << s1 << ' ' << s2 << " #" << ms[s2] << endl;
	}
	return 0;
}