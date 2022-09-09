#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for(cin >> T; T; T -= 1){
        int n, k;
        cin >> n >> k;
        if(n & 1) cout << (n - 1) / 2 << " " << (n - 1) / 2 << " " << 1 << "\n";
        else if(n & 2) cout << (n - 2) / 2 << " " << (n - 2) / 2 << " " << 2 << "\n";
        else cout << n / 2 << " " << n / 4 << " " << n / 4 << "\n";
    }
    return 0;
}