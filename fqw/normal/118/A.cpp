#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

typedef long long int64;
typedef unsigned long long qword;
typedef unsigned int uint;

const int INFI_INT = 1<<30;
const int64 INFI_INT64 = (int64)(1<<30) * (int64)(1<<30);
const double PI = 3.14159265358979323846264338;

template <class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a%b); }
template <class T> T absval(T x) { return x > 0 ? x : -x; }

#define forint(i, s, t) for (int i = (int)(s); i <= (int)(t); ++ i)
#define forintdown(i, s, t) for (int i = (int)(s); i >= (int)(t); -- i)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define movechar(a, b) memmove(b, a, sizeof(a))

char upcase(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    else
        return c;
}

char downcase(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    else
        return c;
}

void solve() {
    char s[111];
    scanf("%s", s);
    for (int i = 0; i < strlen(s); ++ i) {
        char c = s[i];
        char uc = upcase(c);
        char dc = downcase(c);
        if (uc == 'A' || uc == 'O' || uc == 'Y' || uc == 'E' || uc == 'U' || uc == 'I')
            continue;
        printf(".%c", dc);
    }
    printf("\n");
}

int main() {
    /*
    freopen("5.in", "r", stdin);
    freopen("5.out", "w", stdout);
    //*/
    /*
  	for (;;)
    //*/
    solve();
    return 0;
}