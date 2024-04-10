#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            if (a < b) {
                ++a;
                cout << '0';
            }   
            else {
                ++b;
                cout << '1';
            }   
        }
        else {
            if (a < b) {
                --b;
                cout << '1';
            }
            else {
                --a;
                cout << '0';
            }
        }   
    }   
}