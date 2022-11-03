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
	string s1, s2;
	cin >> s1 >> s2;
	int ans = s1.length() + s2.length();
	if (s1.length() > s2.length()) swap(s1, s2);
	s2 = s2.substr(s2.length() - s1.length());
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	s1.push_back('*');
	s2.push_back('#');
	int n = s1.length();
	for (int i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			ans -= i * 2;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}