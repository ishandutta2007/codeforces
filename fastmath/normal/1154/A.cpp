#include<bits/stdc++.h>
using namespace std;
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    vector <int> a(4);
    for (int i = 0; i < 4; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < 3; ++i) {
        cout << a.back() - a[i] << ' ';
    }   
    cout << '\n';


}