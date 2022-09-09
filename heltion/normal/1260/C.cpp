#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1){
        LL a, b, k;
        cin >> a >> b >> k;
        LL d = __gcd(a, b);
        a /= d;
        b /= d;
        if(a > b) swap(a, b);
        LL c = b % a == 1 ? b / a : b / a + 1;
        if(a == 1) c = b - 1;
        if(c >= k) cout << "REBEL\n";
        else cout << "OBEY\n";
    }
    return 0;
}