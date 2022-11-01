#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
#define trace2(args...) trace(args)
#endif

#define MN 1001000

ll t = 1, n, ans, a[MN];
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %s", &n, s);
    str = s;

    ans = n - 1;

    bool ja = false;
    for(int i = 0; i + 1 < n; i++) {
        if (str[i] > str[i + 1]) ja = true;
        else if (str[i] < str[i + 1]) {
            ans = i;
            break;
        }
        else if (!ja) {
            ans = i;
            break;
        }
    }

    for (int i = 0; i <= ans; i++) printf("%c", str[i]);
    for (int i = ans; i >= 0; i--) printf("%c", str[i]);
    puts("");

    if(--t) goto st;
    return 0;
}