#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL n;
        cin >> n;
        cout << (n % 2020 <= n / 2020 ? "YES" : "NO") << "\n";
    }
    return 0;
}