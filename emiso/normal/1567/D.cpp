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

ll t = 1, n, a[MN], sum;
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &sum, &n);

    multiset<ll> ms({sum});

    while((ll)ms.size() < n) {
        int flag = 0;
        auto it2 = ms.begin();
        while(!flag && it2 != ms.end()) {
            ll pot = 1, ss = *it2;
            while(ss > pot && (ss / pot) % 10 == 0) pot *= 10;
            if(ss <= pot) {
                it2++;
                continue;
            }
            
            ms.insert(pot);
            ms.insert(ss - pot);
            ms.erase(it2);
            flag = 1;
            break;
        }
        if(flag) continue;

        auto it = ms.begin();
        while(*it == 1) ++it;
        ll x = *it, ot = 1, tmp = x;
        while(tmp > 0 && tmp % 10 == 0) {
            tmp /= 10;
            ot *= 10;
        }
        if(tmp == 1) {
            ms.insert(x / 10);
            ms.insert(x - x / 10);
        } else {
            ms.insert(x - ot);
            ms.insert(ot);
        }
        ms.erase(it);
    }
    for(ll x: ms) printf("%lld ", x);
    puts("");
    if(--t) goto st;
    return 0;
}