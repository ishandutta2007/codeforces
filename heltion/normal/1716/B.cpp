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
        cout << n << "\n";
        for (int i = 1; i <= n; i += 1) {
            if (i == 1)
                for (int j = 1; j <= n; j += 1) cout << j << " ";
            else for (int j = 1; j <= n; j += 1) {
                if (j > i) cout << j << " ";
                else cout << j % i + 1 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}