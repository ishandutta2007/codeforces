#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int A[3], ans = 0;
        for(int i = 0; i < 3; i += 1) cin >> A[i];
        for(int mask = 0; mask < (1 << 7); mask += 1){
            int a[3], ok = 1;
            for(int i = 0; i < 3; i += 1) a[i] = A[i];
                for(int i = 0; i < 7; i += 1)
                    if((mask >> i) & 1)
                        for(int j = 0; j < 3; j += 1)
                            if(((i + 1) >> j) & 1)
                                a[j] -= 1;
            for(int i = 0; i < 3; i += 1) if(a[i] < 0) ok = 0;
            if(ok) ans = max(ans, __builtin_popcount(mask));
        }
        cout << ans << "\n";
    }
    return 0;
}