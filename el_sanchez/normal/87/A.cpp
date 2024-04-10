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
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define fi first
#define se second
#define sqr(x) ((x)*(x))
#define odd(x) ((x) % 2 == 1)
#define next(i,n) ((i == n) ? 1 : i + 1)   //1..n
#define prev(i,n) ((i == 1) ? n : i - 1)   //1..n

typedef long long int64;

const int MAXN = (int)1E5+100;
const int INF = (int)1E9;
const long double eps = 1e-9;
const long double pi = 3.1415926535897932384626433832795;

using namespace std;

int64 gcd(int a,int b)
{
    while(a!=0 && b!=0)
    {
       if(a>=b) a=a%b;
           else b=b%a;
    }
 return a+b;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int a, b;
    scanf("%d %d", &a, &b);
    int64 g = gcd(a, b);
    int64 nok = (int64(a) * int64(b)) / g;
    int64 x1 = nok / a, x2 = nok / b;
    if (a > b) {
        if (x1 == x2 - 1) {
            printf("Equal");
        } else {
            printf("Masha");
        }
    }
    if (b > a) {
        if (x2 == x1 - 1) {
            printf("Equal");
        } else {
            printf("Dasha");
        }
    }
    if (a == b)
        printf("Equal");

    return 0;
}