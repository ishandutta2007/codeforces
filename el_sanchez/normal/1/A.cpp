#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <complex>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)

#define sqr(x) (x)*(x)
#define odd(x) (x % 2 == 1)
#define next(i,n) ((i == n) ? 1 : i + 1)   //1..n
#define prev(i,n) ((i == 1) ? n : i - 1)   //1..n

typedef long long int64;

const long double eps = 1e-9;
const long double pi = 3.1415926535897932384626433832795;

using namespace std;

int main()
{

    int64 a, b, n;
    scanf("%I64d %I64d %I64d", &a, &b, &n);

    int64 x = (a + n - 1) / n;
    int64 y = (b + n - 1) / n;

    printf("%I64d", (x * y));

    return 0;
}