#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

const int M = 1e9 + 7;
const int INF = 1e9;
const int N = 2e5 + 13;

void solve() {
//    int n;
//    cin >> n;
//
//    vector<int> a(n);
//    for(int i = 0; i< n; i++) {
//        cin >> a[i];
//    }

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << (i == 0 && j == 0 ? 'W' : 'B');
        cout << endl;
    }

}

int main() {
    int t = 1;
    cin >> t;

    while(t--)
        solve();
}