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
const int N = 2e6;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    string str;
    cin >> str;
    string cf = "CODEFORCES";
    int n = str.length();
    int m = cf.length();
    int l = 0;
    for (int i = 0; i < min(n, m); i++)
    {
        if (str[i] == cf[i]) l++;
        else break;
    }
    int r = 0;
    for (int i = 0; i < min(n, m); i++)
    {
        if (str[n - i - 1] == cf[m - i - 1]) r++;
        else break;
    }
    if (l + r >= m) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}