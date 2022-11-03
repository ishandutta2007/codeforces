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
const int N = 1e5 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<string> vs;
	for (int i = 0; i < 2; i++)
	{
		string s;
		s.push_back(i + 'A');
		s.push_back('a');
		for (int j = 0; j < 26; j++)
		{
			s.back() = j + 'a';
			vs.push_back(s);
		}
	}
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) a[i] = i;
	for (int i = 0; i <= n - k; i++)
	{
		string str;
		cin >> str;
		if (str == "NO")
		{
			a[i + k - 1] = a[i];
		}
	}
	for (int i = 0; i < n; i++) cout << vs[a[i]] << ' ';
	return 0;
}