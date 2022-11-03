#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<li> s(2, 0ll);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s[i % 2] += a[i];
    }

    if(s[0] <= s[1]) {
        for(int i = 0; i < n; i++) {
            cout << (i % 2 == 0 ? 1 : a[i]) << ' ';
        }
    } else {
        for(int i = 0; i < n; i++) {
            cout << (i % 2 == 1 ? 1 : a[i]) << ' ';
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}