#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 50000;
int s[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int a, b, q;
        cin >> a >> b;
        int m = a * b / gcd(a, b);
        for(int i = 1; i <= m; i += 1) s[i] = i % a % b != i % b % a;
        for(int i = 1; i <= m; i += 1) s[i] += s[i - 1];
        auto f = [&](const LL& x)->LL{
            return x / m * s[m] + s[x % m];
        };
        for(cin >> q; q; q -= 1){
            LL l, r;
            cin >> l >> r;
            cout << f(r) - f(l - 1) << " ";
        }
        cout << "\n";
    }
    return 0;
}