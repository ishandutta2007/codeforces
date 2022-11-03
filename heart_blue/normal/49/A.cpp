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

const int INF = 1e6 + 3;
const int N = 1e3 + 1;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string vo = "aeiouy";
	map<char, int> m;
	for (int i = 0; i < vo.length(); i++) m[vo[i]] = 1;
	char c;
	int ans = 0;
	while (cin >> c)
	{
		c = tolower(c);
		if (islower(c))
		{
			if (m.count(c)) ans = 1;
			else ans = 0;
		}
	}
	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}