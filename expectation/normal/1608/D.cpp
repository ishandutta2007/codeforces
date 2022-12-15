//#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/stack:32777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
using namespace std;
 
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define x first
#define y second
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg
 
typedef long long Int;
typedef long long LL;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const int MOD = 998244353;
int n;
int n1, n2;
int b;
LL f[300000];
 
LL mrev(LL a, LL step) {
    LL res = 1;
    while (step) {
        if (step&1) {
            res = (res*a)%MOD;
            step--;
        } else {
            a = (a*a)%MOD;
            step /= 2;
        }
    }
    return res;
}
 
int q = 0;
bool h = false;
int T1 = true, T2 = true;
int main()
{
    f[0] = 1;
    FOR (i,1,300000) f[i] = (f[i-1]*i)%MOD;
    cin >> n;
    FOR (i,0,n) {
        string s;
        cin >> s;
        if (s[0] == '?') n1++;
        if (s[0] == 'W') b++;
        if (s[1] == '?') n1++;
        if (s[1] == 'W') b++;
        if (s == "??") q++;
        if (s == "WW") h=true;
        if (s == "BB") h=true;
        if (s[0] == 'W') T1 = false;
        if (s[0] == 'B') T2 = false;
        if (s[1] == 'B') T1 = false;
        if (s[1] == 'W') T2 = false;
    }
    if (b > n || n1+b < n) {
        cout << 0;
        return 0;
    }
    LL ans = f[n1]*mrev(f[n-b], MOD-2)%MOD*mrev(f[n1-n+b], MOD-2)%MOD;
    if (h) {
        cout << ans;
        return 0;
    }
    ans = (ans + MOD - mrev(2,q))%MOD;
    cout << (ans + T1 + T2)%MOD;
    return 0;
}