#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for(cin >> T; T; T -= 1){
        LL n;
        cin >> n;
        if(n % 2050) cout << "-1\n";
        else{
            auto s = to_string(n / 2050);
            int ans = 0;
            for(char c : s) ans += c - '0';
            cout << ans << "\n";
        }
    }
    return 0;
}