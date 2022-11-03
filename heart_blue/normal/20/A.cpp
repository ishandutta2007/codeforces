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
const LL INF = 1e9 + 1;
const int N = 3e3;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	while (str.length() > 1 && str.back() == '/') str.pop_back();
	cout << str[0];
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == str[i - 1] && str[i] == '/') continue;
		cout << str[i];
	}

	return 0;
}