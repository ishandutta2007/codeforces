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
	vector<string> vs = {
		"Power","purple",
		"Time","green",
		"Space","blue",
		"Soul","orange",
		"Reality","red",
		"Mind","yellow"
	};
	map<string, string> ms;
	for (int i = 0; i < vs.size(); i += 2) ms[vs[i + 1]] = vs[i];
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		ms.erase(str);
	}
	cout << ms.size() << endl;
	for (auto &p : ms) cout << p.second << endl;
	return 0;
}