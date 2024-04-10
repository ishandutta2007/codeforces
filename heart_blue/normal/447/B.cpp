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
int a[N];
int getsum(int n)
{
    return n*(n + 1) / 2;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    string str;
    cin >> str;
    int n;
    cin >> n; 
    int maxv = 0;
    for (int i = 0; i < 26; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        maxv = max(maxv, x);
    }
    int ans = 0;
    for (int i = 0; i < str.length(); i++)
    {
        ans += a[str[i] - 'a'] * (i + 1);
    }
    ans += (getsum(str.length() + n) - getsum(str.length()))*maxv;
    cout << ans << endl;
    return 0;
}