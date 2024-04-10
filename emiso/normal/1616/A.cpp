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
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    set<int> ja, ja2;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] == 0 || !ja.count(abs(a[i]))) {
            ja.insert(abs(a[i]));
        } else {
            ja2.insert(abs(a[i]));
        }
    }

    printf("%lld\n", ja.size() + ja2.size());
    if(--t) goto st;
    return 0;
}