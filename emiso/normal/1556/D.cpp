#include <bits/stdc++.h>

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

#define MN 1001000

ll t = 1, n, ans, a[MN], k;
//char s[MN]; string str;

map<pair<string, pair<int, int>>, int> memo;
int ask(int i, int j, string type) {
    if(i > j) swap(i, j);
    if(memo.count({type, {i, j}})) return memo[{type, {i, j}}];
    int x;
    printf("%s %d %d\n", type.c_str(), i, j); fflush(stdout);
    scanf("%d", &x);
    return memo[{type, {i, j}}] = x;
}

int b(int x, int i) {
    return ((x & (1 << i)) != 0);
}

int main() {
    scanf("%lld %lld", &n, &k);

    int o12 = ask(1, 2, "or"), o13 = ask(1, 3, "or");
    int a12 = ask(1, 2, "and"), a23 = ask(2, 3, "and");

    int x = 0;
    for(int i = 0; i < 32; i++) {
        if(!b(o12,i)) continue;
        if(!b(o13,i)) continue;
        if(b(a23,i)) if(!b(a12,i)) continue;
        x |= (1 << i);
    }

    a[1] = x;
    for(int i = 2; i <= n; i++) {
        int oq = ask(1, i, "or"), aq = ask(1, i, "and");
        for(int bb = 0; bb < 32; bb++) {
            if(b(aq, bb)) continue;
            if(!b(oq, bb)) continue;
            a[i] |= (1 << bb);
        }
        a[i] ^= a[1];
    }
    sort(a + 1, a + n + 1);

    printf("finish %lld\n", a[k]); fflush(stdout);
    return 0;
}