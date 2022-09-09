#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL n;
        cin >> n;
        LL res = 0;
        for(LL i = 0; i <= n / 2; i += 1){
            res += 2 * i * 4 * i;
        }
        cout << res << "\n";
    }
    return 0;
}