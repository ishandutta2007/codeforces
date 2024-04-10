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
        cout << 4 * n / gcd(4 * n, n + 1) + 1 << "\n";
    }
    return 0;
}