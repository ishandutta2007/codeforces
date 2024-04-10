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

ll n;

int query(int l, int r) {
    printf("?");
    for(int i = 1; i < n; i++) printf(" %d", l);
    printf(" %d\n", r);
    fflush(stdout);

    int x;
    scanf("%d", &x);
    return x;
}

int a[110];

int main() {
    scanf("%lld", &n);
    
    int last = 1;
    for(int i = n; i > 1; i--) {
        if(!query(1, n+2-i)) {
            last = i;
            break;
        }
    }
    
    a[n] = last;
    for(int i = 1; i <= n; i++) {
        if(i == last) continue;
        
        int x = 0;
        if(i < last) x = query(last-i+1, 1);
        else x = query(1, i-last+1);

        assert(x > 0);
        a[x] = i;
    }

    printf("!");
    for(int i = 1; i <= n; i++) printf(" %d", a[i]);
    puts("\n");
    fflush(stdout);
    return 0;
}