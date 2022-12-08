#include <cstdio>
#include <iostream>

#include <cassert>

using namespace std;

typedef long long ll;
const ll CUT = 1e7;

ll N, K, L, R;

int main() {
    scanf("%lld%lld%lld%lld", &N, &L, &R, &K);

    ll ans;
    
    if(N <= CUT) {
        ll t = (R - L + N)%N;
        for(ans = N;ans > 0;ans--){
            ll r = ((K - 1 + (ans + N))%(ans + N)) + 1;
            ll b = r - t - 1;      //or r - t - 2
            
            //cout << ans << ' ' << r << ' ' << b << '\n';
            
            if(b >= 0 and b >= ans - (N - t) and b <= ans - 1 and b <= t) break; else b--;
            if(b >= 0 and b >= ans - (N - t) and b <= ans - 1 and b <= t) break;
        }
        if(ans == 0) {
            if(((K + N - 1)%N) != t) ans = -1;
        }
    } else {
        ans = -1;
        ll t = (R - L + N)%N, tp;
        for(int c = 1;c <= K/N + 1;c++) {
            
            ll lb = (K + c)/(c + 1);
            ll ub = K/c;
            
            if(N > lb) lb = N;
            if(2*N < ub) ub = 2*N;
            
            
            if((tp = (K - t)/c) < ub) ub = tp;
            if((tp = (K - 2*t + c - 1)/c) > lb) lb = tp;
            if((tp = (K - 2*t + 2*N - 1)/(c + 1)) < ub) ub = tp;
            if((tp = (K + N - t + c)/(c + 1)) > lb) lb = tp;
            
            
            //cout << lb << ' ' << ub << '\n';
            if(ub >= lb and (tp = ub - N) > ans) ans = tp;
            
        }
        if(K >= t + 1 and K <= (t + 1) * 2) if((tp = N - t + (K - 1) - t) > ans) ans = tp;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}