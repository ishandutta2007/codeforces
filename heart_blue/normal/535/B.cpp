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
const int N = 3e3 + 10;
char c[N][N];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);

    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    int t = 1;
    int ans = 0;
    for (int i = 0; i < str.length(); i++)
    {
        ans += t;
        if (str[i] == '7') ans += t;
        t <<= 1;
    }
    cout << ans << endl;
    return 0;
}