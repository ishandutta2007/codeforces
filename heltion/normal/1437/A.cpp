#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int l, r;
        cin >> l >> r;
        cout << (l * 2 >= r + 1 ? "YES\n" : "NO\n");
    }
    return 0;
}