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
const int N = 2e6 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	map<string, string> m1, m2;
	cin >> n;
	while (n--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		if (m2.count(s1)) s1 = m2[s1];
		m1[s1] = s2;
		m2[s2] = s1;
	}
	cout << m1.size() << endl;
	for (auto &p : m1)
	{
		cout << p.first << ' ' << p.second << endl;
	}
	return 0;
}