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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
pair<int, int> p[N];
map<pair<int, int>, int> mc;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		for (auto& c : str)
			if (!isdigit(c)) c = ' ';
		stringstream sin(str);
		int a, b, c;
		sin >> a >> b >> c;
		a += b;
		int g = gcd(a, c);
		a /= g, c /= g;
		p[i] = make_pair(a, c);
		mc[p[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << mc[p[i]] << ' ';
	}
	return 0;
}