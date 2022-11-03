#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;

int add(int a, int b) {
    int res = a + b;
    if(res >= M)
        res -= M;
    return res;
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }

    sort(a.begin(), a.end());

    if(s == 0) {
        cout << "NO" << endl;
        return;
    }

    if(s > 0)
        sort(a.rbegin(), a.rend());

    cout << "YES" << endl;
    for(auto x : a)
        cout << x << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}