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

const int INF = 1e6 + 3;
const int N = 1e3 + 1;
int getans(int n, int b)
{
    int ret = 0;
    while (n)
    {
        ret += n%b;
        n /= b;
    }
    return ret;
}
int gcd(int n, int m)
{
    return m == 0 ? n : gcd(m, n%m);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 2; i < n; i++) sum += getans(n, i);
    n -= 2;
    int g = gcd(n, sum);
    sum /= g;
    n /= g;
    cout << sum << '/' << n << endl;
    return 0;
}