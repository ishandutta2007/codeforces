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
const LL INF = 1e9+1;
const int N = 1e6 + 10;
int a[26];
int b[26];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    MEM(a, 0);
    MEM(b, 0);
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) a[str[i] - 'a']++;
    cin >> str;
    for (int i = 0; i < str.length(); i++) b[str[i] - 'a']++;
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        ans += min(a[i], b[i]);
        if (a[i] == 0 && b[i] != 0)
        {
            ans = -1;
            break;
        }
    }
    if (ans == 0) ans = -1;
    cout << ans << endl;
    return 0;
}