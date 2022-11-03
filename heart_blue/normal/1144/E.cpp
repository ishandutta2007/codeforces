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
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	int o = 0;
	for (auto &c : s1) c = toupper(c);
	for (int i = n - 1; i >= 0; i--)
	{
		s1[i] += s2[i] - 'a';
		if (i > 0 && s1[i] > 'Z') s1[i] -= 26, s1[i - 1]++;
	}
	for (int i = 0; i < n; i++)
	{
		int t = (s1[i] - 'A') & 1;
		if (i + 1 != n) s1[i + 1] += t * 26;
		s1[i] = 'a' + (s1[i] - 'A') / 2;
	}
	cout << s1 << endl;
	return 0;
}