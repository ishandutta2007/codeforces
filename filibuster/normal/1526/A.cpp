#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<li, li>;

const int INF = 1e9 + 14;
const int M = 998244353;
const int N = 2e5 + 13;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n * 2);
    for(int i = 0; i < n * 2; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ' << a[n + i] << ' ';
    }
    cout << endl;
}


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}