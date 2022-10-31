#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
template<typename... Args> void recInit(Args... args) {}
template<typename... Args> void recEnd(Args... args) {}
#define trace2(args...) trace(args)
#endif

ll t, n, ans, a[MN];
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    ans = 0;
    scanf("%lld", &n);

    str = "";
    if(n % 2) {
        str += "7";
        n -= 3;
    }
    str += string(n / 2, '1');

    printf("%s\n", str.c_str());
    if(--t) goto st;
    return 0;
}