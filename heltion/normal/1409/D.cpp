#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL n, s;
        cin >> n >> s;
        LL m = n;
        while(true){
            int sum = 0;
            for(LL x = m; x; x /= 10) sum += x % 10;
            if(sum <= s) break;
            LL x = m, p = 0;
            for(; x % 10 == 0; p += 1) x /= 10;
            m = x + 1;
            for(; p; p -= 1) m = m * 10;
        }
        cout << m - n << "\n";
    }
    return 0;
}