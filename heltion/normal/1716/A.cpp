#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        if (n == 1) cout << 2 << "\n";
        else cout << (n + 2) / 3 << "\n";
    }
    return 0;
}