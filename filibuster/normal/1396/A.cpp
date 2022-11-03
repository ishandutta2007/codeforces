#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int A = 26;

/*
*/

int a[N];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(n == 1) {
        cout << 1 << ' ' << 1 << ' ' << -a[0] << endl;
        cout << 1 << ' ' << 1 << ' ' << 0 << endl;
        cout << 1 << ' ' << 1 << ' ' << 0 << endl;
        return;
    }

    cout << 1 << ' ' << n << endl;
    for(int i = 0; i < n - 1; i++) {
        cout << -a[i] * 1ll * n << ' ';
    }
    cout << 0 << endl << 1 << ' ' << n - 1 << endl;

    for(int i = 0; i < n - 1; i++) {
        cout << a[i] * 1ll * (n - 1) << ' ';
    }
    cout << endl << n << ' ' << n << endl << -a[n - 1] << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}