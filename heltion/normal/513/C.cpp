#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using LD = long double;
int L[5], R[5];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i += 1)
        cin >> L[i] >> R[i];
    LD ans = 0;
    for(int i = 0; i < n; i += 1)
        for(int j = 0; j < n; j += 1) if(j != i)
            for(int k = L[i]; k <= R[i]; k += 1){
                LD pans = 1;
                for(int x = 0; x < n; x += 1) if(x != i and x != j)
                    pans *= max(min(R[x], k - (x < i)) - L[x] + 1, 0);
                pans *= max(R[j] - max(L[j], k + (j > i)) + 1, 0);
                ans += k * pans;
            }
    for(int i = 0; i < n; i += 1) ans /= R[i] - L[i] + 1;
    cout << fixed << setprecision(20) << ans;
    return 0;
}