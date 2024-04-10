#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL a, K;
        cin >> a >> K;
        for(int i = 1; i < K; i += 1){
            LL minD = 9, maxD = 0;
            for(LL x = a; x; x /= 10){
                minD = min(x % 10, minD);
                maxD = max(x % 10, maxD);
            }
            if(minD == 0) break;
            a += minD * maxD;
        }
        cout << a << "\n";
    }
    return 0;
}