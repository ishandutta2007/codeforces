#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

int n;
int a[MAXN];

int mod(int x) {
    return (x % n + n) % n;
}   

bool used[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   

    for (int t = 0; t < n; ++t) {
        bool ch = 1;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                ch &= (mod(a[i] + t) == i);
            }   
            else {
                ch &= (mod(a[i] - t) == i);
            }   
        }   
        if (ch) {
            cout << "Yes\n";
            exit(0);
        }   
    }   

    cout << "No\n";
    return 0;
}