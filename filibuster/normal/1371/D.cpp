#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int N = 2e5 + 13;
const int M = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;

    if(k == 0) {
        cout << 0 << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                cout << 0;
            cout << endl;
        }

        return;
    }

    if(k % n == 0) {
        cout << 0 << endl;
    } else {
        cout << 2 << endl;
    }

    int x = k / n;

    for(int i = 0; i < k % n; i++) {
        vector<int> a(n, 0);
        for(int j = 0; j <= x; j++)
            a[(i + j) % n] = 1;
        for(auto a1 : a)
            cout << a1;
        cout << endl;
    }

    for(int i = k % n; i < n; i++) {
        vector<int> a(n, 0);
        for(int j = 0; j < x; j++)
            a[(i + j) % n] = 1;
        for(auto a1 : a)
            cout << a1;
        cout << endl;
    }

//    vector<>
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}