#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

bool check(array<int, 5> a, array<int, 5> b) {
    int cnt = 0;
    for (int i = 0; i < 5; ++i) {
        if (a[i] <= b[i]) {
            ++cnt;
        }
    }
    return cnt >= 3;
}

void solve() {
    int n;
    cin >> n;
    vector<array<int, 5>> a(n);
    int now = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> a[i][j];
        }
        if (check(a[i], a[now])) {
            now = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!check(a[now], a[i])) {
            cout << -1 << '\n';
            return;   
        }
    }
    cout << now + 1 << '\n';
}

int main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE
}