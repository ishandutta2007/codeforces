#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL A, B;
        cin >> A >> B;
        if(B == 1) cout << "NO\n";
        else if(B == 2) cout << "YES\n" << A << " " << 3 * A << " " << 4 * A <<  "\n";
        else cout << "YES\n" << A << " " << (B - 1) * A << " " << A * B <<  "\n";
    }
    return 0;
}