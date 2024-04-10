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
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int check(string &str)
{
    int n = str.length();
    int ret = 0;
    for (int i = 1; i < n; i++)
    {
        if (str[i] == 'K' && str[i-1] == 'V') ret ++;
    }
    return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    string str;
    cin >> str;
    int ans = 0;
    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        str[i] = 'V';
        ans = max(ans, check(str));
        str[i] = 'K';
        ans = max(ans, check(str));
        str[i] = c;
    }
    cout << ans << endl;
	return 0;
}