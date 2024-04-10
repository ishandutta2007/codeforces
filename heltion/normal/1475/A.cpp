#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL n;
        for(cin >> n; n % 2 == 0; n /= 2);
        cout << (n == 1 ? "NO" : "YES") << "\n";
    }
    return 0;
}