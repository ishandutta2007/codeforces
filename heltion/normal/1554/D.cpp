#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        for (int i = 0; i < n / 2; i += 1) cout << "a";
        cout << "b";
        for (int i = 0; i < n / 2 - 1; i += 1) cout << "a";
        if ((n & 1) and n > 1) cout << "c";
        cout << "\n";
    }
    return 0;
}