#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 1e6 + 13;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int mn = INF;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min(a[i], mn);
    }

    vector<int> b = a;
    sort(b.begin(), b.end());

    for(int i = 0; i < n; i++)
        if(a[i] != b[i] && b[i] % mn > 0) {
            cout << "NO" << endl;
            return;
        }

    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}