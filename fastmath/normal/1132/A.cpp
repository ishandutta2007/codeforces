#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == d && (a || !c)) {
        cout << "1\n";
    }   
    else {
        cout << "0\n";
    }   
}