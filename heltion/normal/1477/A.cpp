#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    function<LL(LL, LL)> gcd = [&](LL A, LL B){
        return B ? gcd(B, A % B) : A;
    };
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        LL k;
        cin >> n >> k;
        LL d = 0;
        vector<LL> x(n);
        for(LL& a : x) cin >> a;
        for(LL a : x) d = gcd(d, abs(a - x[0]));
        cout << ((k - x[0]) % d == 0 ? "YES" : "NO") << "\n";
    }
    return 0;
}