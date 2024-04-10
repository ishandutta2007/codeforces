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

const int INF = 1e9 + 7;
const int N = 2e5 + 1;
int change(int n)
{
    int ret = 0;
    int t = 1;
    while (n)
    {
        if (n % 10)
        {   
            ret += t*(n % 10);
            t *= 10;
        }
        n /= 10;
    }
    return ret;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int a, b, c;
    cin >> a >> b;
    c = a + b;
    a = change(a);
    b = change(b);
    c = change(c);
    if (a + b == c) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}