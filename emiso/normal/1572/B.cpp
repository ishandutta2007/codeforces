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

    ll xo = 0, f[] = {0, 0};
    vector<int> ones;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        f[a[i]]++;
        xo ^= a[i];
        if(a[i]) ones.push_back(i);
    }

    if(xo == 1 || f[0] == 0) puts("NO");
    else {
        vector<int> op;
        int l = 0, r = 0;
        while(1) {
            while(r < n) {
                if(a[l] == 0) {
                    l++; r = l;
                } else if(a[r] == 1) {
                    r++;
                } else break;
            }

            if(l == n) break;
            else if(l == 0 && r == n) break;
            else if((r - l) % 2 == 0) {
                if(l > 0) {
                    while(l < r) {
                        op.push_back(l);
                        assert(a[l-1] == 0 && a[l] == 1 && a[l+1] == 1);
                        a[l-1] = a[l] = a[l+1] = 0;
                        l += 2;
                    }
                } else {
                    for(int j = r; j > l; j -= 2) {
                        op.push_back(j-1);
                        assert(a[j-2] == 1 && a[j-1] == 1 && a[j] == 0);
                        a[j-2] = a[j-1] = a[j] = 0;
                    }
                }
            } else {
                if(r + 1 >= n) break;
                ll tmp = a[r-1] ^ a[r] ^ a[r+1];
                a[r-1] = a[r] = a[r+1] = tmp;
                op.push_back(r);
                if(tmp == 0) r--;
            }
        }

        int can = 1;
        for(int i = 0; i < n; i++) can &= (a[i] == 0);
        if(!can) puts("NO");
        else {
            printf("YES\n%d\n", (int)op.size());
            for(auto x : op) printf("%d ", x);
            puts("");
        }
    }
    if(--t) goto st;
    return 0;
}