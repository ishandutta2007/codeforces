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
const int N = 1e3 + 10;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s1, s2;
	cin >> s1 >> s2;
	int n1 = s1.length();
	int n2 = s2.length();
	int sum = 0;
	for (int i = 0; i < n2 - n1; i++) sum += s2[i] - '0';
	LL ans = 0;
	int len = n2 - n1 + 1;
	for (int i = 0; i < n1; i++)
	{
		sum += s2[len + i - 1] - '0';
		if (s1[i] == '1') ans += len - sum;
		else ans += sum;
		sum -= s2[i] - '0';
	}
	cout << ans << endl;
	return 0;
}