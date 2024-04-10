#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000;
LL a[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n;
    cin >> n;
    for(int i = 1; i <= n; i += 1) cin >> a[i];
    if(n == 1){
        cout << "1 1\n" << -a[1] << "\n";
        cout << "1 1\n0\n1 1\n0\n";
    }
    else{
        cout << "1 " << n << "\n";
        for(int i = 1; i <= n; i += 1){
            LL b = ((n - 1) - (a[i] % (n - 1))) * n;
            a[i] += b;
            cout << b << " ";
        }
        cout << "\n";
        cout << "1 " << n - 1 << "\n";
        for(int i = 1; i < n; i += 1) cout << -a[i] << " ";
        cout << "\n";
        cout << n  << " " << n << "\n" << -a[n] << "\n";
    }
    return 0;
}