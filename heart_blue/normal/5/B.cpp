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
#include <cassert>
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;

vector<string> vs;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	int x = 0;
	while (getline(cin, str))
	{
		vs.push_back(str);
		x = max(x, (int)str.length());
	}
	cout << string(x + 2, '*') << endl;
	int flag = 0;
	for (auto &str : vs)
	{
		cout << '*';
		int len = x - str.length();
		if (len & 1) flag ^= 1;
		if(len % 2 == 0 || flag) cout << string(len / 2, ' ');
		else cout << string(len - len / 2, ' ');
		cout << str;
		if (len % 2 == 0 || flag) cout << string(len - len / 2, ' ');
		else cout << string(len / 2, ' ');
		cout << '*' << endl;
	}

	cout << string(x + 2, '*') << endl;
	return 0;
}