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
	string str;
	int n, m;
	cin >> n >> m;
	while (n--)
	{
		cin >> str;
	}
	vector<string> vs;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '.') str[i] = ' ';
	}
	stringstream sin(str);
	string s1;
	while (sin >> s1)
	{
		vs.push_back(s1);
	}
	cout << vs.size() << endl;
	return 0;
}