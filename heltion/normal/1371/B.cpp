#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL t, n, r;
    for(cin >> t; t; t -= 1){
        cin >> n >> r;
        LL k = min(n - 1, r);
        LL ans = (k + 1) * k / 2;
        cout << ans + (r >= n) << "\n";
    }
    return 0;
}

//n <= r 1
//n > r r