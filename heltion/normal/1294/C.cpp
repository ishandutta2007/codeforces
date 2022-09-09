#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
using LL = long long;
void solve(){
    int n;
    cin >> n;
    for(int a = 2; a * (a + 1) * (a + 2) <= n; a += 1) if(n % a == 0)
        for(int b = a + 1; a * b * (b + 1) <= n; b += 1) if(n / a % b == 0){
            cout << "YES\n" << a << " " << b << " " << n / a / b << "\n";
            return;
        }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1) solve();
    return 0;
}