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
char s[MN]; string str, pat;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%s", &s); str = s;
    scanf("%s", &s); pat = s;

    for(int i = 0; !ans && i < str.size(); i++) {
        for(int j = i; !ans && j < str.size(); j++) {
            int can = 1, l = 0;
            for(int k = i; can && k <= j; k++, l++)
                if(l >= pat.size() || str[k] != pat[l])
                    can = 0;

            for(int k = j-1; can && l < pat.size(); k--, l++)
                if(k < 0 || str[k] != pat[l])
                    can = 0;
            if(can && l == pat.size()) ans = 1;
        }
    }

    puts(ans ? "Yes" : "No");
    if(--t) goto st;
    return 0;
}