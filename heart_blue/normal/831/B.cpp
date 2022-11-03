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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < N; i++) a[i] = i;
	for (int i = 0; i < 26; i++)
	{
		a[s1[i]] = s2[i];
		a[s1[i] - 'a' + 'A'] = s2[i] - 'a' + 'A';
	}
	string str;
	cin >> str;
	for (auto &c : str) c = a[c];
	cout << str << endl;
	return 0;
}