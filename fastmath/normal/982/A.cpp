#include <bits/stdc++.h>

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '1' && s[i + 1] == '1') {
            cout << "No\n";
            return 0;
        }
    }
    
    for (int i = 1; i < n - 1; ++i) {
        if (s[i] == '0' && s[i - 1] == '0' && s[i + 1] == '0') {
            cout << "No\n";
            return 0;
        }
    }

    if (n == 1) {
        if (s[0] == '0') {
            cout << "No\n";
        }
        else {
            cout << "Yes\n";
        }
        return 0;
    }

    if (s[0] == '0' && s[1] == '0') {
        cout << "No\n";
        return 0;
    }

    if (s[n - 1] == '0' && s[n - 2] == '0') {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    return 0;
}