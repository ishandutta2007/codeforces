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

const LL INF = 1e7 + 7;
const int N = 1e3 + 10;

int str2num(string str)
{
	int h = (str[0] - '0') * 10 + str[1] - '0';
	int m = (str[3] - '0') * 10 + str[4] - '0';
	return h * 60 + m;
}

void getans(int n)
{
	printf("%02d:%02d\n", n / 60, n % 60);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str1, str2;
	cin >> str1 >> str2;
	int h1 = str2num(str1);
	int h2 = str2num(str2);
	int ans = h1 - h2;
	if (ans < 0) ans += 24 * 60;
	getans(ans);
	return 0;
}