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

ll t = 1, n, ans, a[MN], ok[MN];
//char s[MN]; string str;

int guess(int i) {
    int res;
    printf("? %d\n", i);
    fflush(stdout);
    scanf("%d", &res);
    return res;
}

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    for (int i = 1; i <= n; i++) {
        ok[i] = 0;
    }
    
    //guess(1);
    int num = -1;

    for (int i = 1; i <= n; i++) {
        if (ok[i]) continue;
        
        int shift = num;
        vector<int> ord;
        while (true) {
            num++;
            ord.push_back(guess(i));
            if (ord.size() > 1 && ord[0] == ord.back()) {
                ord.pop_back();
                break;
            }
        }
        trace(shift);
        trace(ord);
        for (int j = 0, pos = i; j < ord.size(); j++) {
            trace2(shift, ord.size(), shift % (int) ord.size());
            int idx = (j - shift % (int) ord.size() + ord.size()) % ord.size();
            trace2(pos, idx);
            ok[pos] = ord[idx];
            pos = ord[idx];
        }
    }

    printf("!");
    for (int i = 1; i <= n; i++) {
        printf(" %lld", ok[i]);
    }
    puts("");
    fflush(stdout);

    if(--t) goto st;
    return 0;
}