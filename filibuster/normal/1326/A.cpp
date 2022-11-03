#include <bits/stdc++.h>

#define f first
#define s second
#define forn(i, n) for(int i = 0; i < n; i++)

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;

    if(n == 1) {
        cout << -1 << endl;
    } else {
        cout << 5;
        for(int i = 1; i < n; i++)
            cout << 7;
        cout << endl;
    }

//    vector<int> a(n);
//    forn(i, n) {
//        cin >> a[i];
//    }
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}