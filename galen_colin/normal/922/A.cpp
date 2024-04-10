#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    ll x, y; cin >> x >> y;
    if (y == 0) {
        cout << "No\n";
    } else if (y == 1) {
        cout << (x > 0 ? "No\n" : "Yes\n");
    } else {
        --y;
        x -= y;
        
        cout << (x % 2 == 0 && x >= 0 ? "Yes\n" : "No\n");
    }
}