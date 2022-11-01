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

ll t = 1, n, ans, a[MN];
//char s[MN]; string str;

int get(int x) {
    for(int i = 1; i <= n; i++)
        if(a[i] == x)
            return i;
    assert(false);
    return 0;
}

vector<int> ret;
void op(int p) {
    ret.push_back(p);
    assert(p % 2);
    for(int i = 1, j = p; i < j; i++, j--)
        swap(a[i], a[j]);
}

int main() {
    scanf("%lld", &t);
    st: ans = 1;
    
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        if((i % 2) != (a[i] % 2)) ans = 0;
    }

    if(!ans) puts("-1");
    else {
        ret.clear();
        for(int i = n; i > 1; i -= 2) {
            int X = get(i);
            op(X);
            int x = get(i-1);
            op(x-1);
            op(x+1);
            op(3);
            op(i);
        }

        printf("%d\n", (int)ret.size());
        for(int x : ret) printf("%d ", x);
        puts("");

        for(int i = 1; i <= n; i++)
            assert(a[i] == i);
    }

    if(--t) goto st;
    return 0;
}