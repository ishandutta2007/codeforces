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

ll t = 1, n, ans[100100], a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    
    scanf("%lld", &n);

    pair<int, int> last;
    map<int, int> idx;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(idx.count(a[i])) {
            ans[i] = 1;
            ans[idx[a[i]]] = -1;
            last = {i, idx[a[i]]};
            idx.erase(a[i]);
        } else if(idx.count(-a[i])) {
            ans[i] = 1;
            ans[idx[-a[i]]] = 1;
            last = {i, idx[-a[i]]};
            idx.erase(-a[i]);
        }
        else idx[a[i]] = i;
    }

    if(!idx.empty()) {
        int li = idx.begin()->second;
        idx.erase(idx.begin());
        
        ll sum = 0;
        for(auto tt : idx) {
            int i = tt.second;
            if(a[i] < 0) ans[i] = -a[li];
            else ans[i] = a[li];
            sum += abs(a[i]);
        }
        if(idx.size() == 0) {
            int i = last.first;
            if(a[i] < 0) ans[i] = -a[li];
            else ans[i] = a[li];
            sum += abs(a[i]);

            i = last.second;
            if(a[i] < 0) ans[i] = -a[li];
            else ans[i] = a[li];
            sum += abs(a[i]);
        }
        ans[li] = -sum;
    }

    ll checksum = 0, checkprod = 0;
    for(int i = 0; i < n; i++) {
        checksum += abs(ans[i]);
        checkprod += a[i] * ans[i];
    }
    assert(checksum <= 1'000'000'000);
    assert(checkprod == 0);

    for(int i = 0; i < n; i++)
        printf("%lld ", ans[i]);
    puts("");
    if(--t) goto st;
    return 0;
}