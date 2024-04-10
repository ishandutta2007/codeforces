#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

int n;
int a[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] &= 1;
    }   
    
    int sz = 0, l = 0;
    for (int i = 0; i < n; ++i) {
        if (sz == 0) {
            sz = 1;
            l = a[i];
        }   
        else if (l == a[i]) {
            l ^= 1;
            --sz;
        }   
        else {
            l ^= 1;
            ++sz;
        }   
    }

    if (sz <= 1) {
        cout << "YES\n";
    }   
    else {
        cout << "NO\n";
    }   

    return 0;
}