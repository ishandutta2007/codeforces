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
const int N = 2e5 + 10;
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string one = "one";
	string zero = "zero";
	string str;
	int n;
	cin >> n;
	cin >> str;
	for (auto& c : str)
	{
		cnt[c]++;
	}
	int minv1 = min({ cnt['o'],cnt['e'],cnt['n'] });
	cnt['o'] -= minv1;
	cnt['e'] -= minv1;
	int minv0 = min({ cnt['z'],cnt['e'],cnt['r'],cnt['o'] });
	while (minv1--) cout << 1 << ' ';
	while (minv0--) cout << 0 << ' ';
	return 0;
}