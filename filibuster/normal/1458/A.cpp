#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

void solve() {

}

li gcd(li a, li b) {
    if(b == 0)
        return a;
    while(a % b != 0) {
        a %= b;
        swap(a, b);
    }

    return b;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

//    cout << gcd(6, 8) << endl;

    int n, m;
    cin >> n >> m;

    vector<li> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int j = 0; j < m; j++) {
        cin >> b[j];
    }

    li g = 0;
    for(int i = 1; i < n; i++) {
        g = gcd(g, abs(a[i] - a[0]));
    }

    for(int i = 0; i < m; i++) {
        cout << gcd(g, b[i] + a[0]) << ' ';
    }
    cout << endl;

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}