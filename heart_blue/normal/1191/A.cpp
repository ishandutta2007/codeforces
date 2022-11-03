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
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a[4] = { 0,4,2,3 };
	string op = "DACB";
	int n;
	cin >> n;
	tuple<int,int, int> ans;
	for (int i = 0; i < 3; i++)
	{
		ans = max({ a[(n + i) % 4],op[(n + i) % 4],i }, ans);
	}
	cout << get<2>(ans) << ' ' << char(get<1>(ans)) << endl;
	return 0;
}