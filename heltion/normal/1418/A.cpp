#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL x, y, k;
        cin >> x >> y >> k;
        cout << k + (k * (y + 1) - 1 + x - 2) / (x - 1) << "\n";
    }
    return 0;
}