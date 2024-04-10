#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b){
    return b ? gcd(b, a % b) : a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL m, d, w;
        cin >> m >> d >> w;
        LL n = min(d, m);
        //w | (y - x) * (d - 1)
        //x < y <= n
        LL k = w / gcd(d - 1, w);
        LL x = n / k;
        cout << n * x - x * (x + 1) / 2 * k << "\n";
    }
    return 0;
}