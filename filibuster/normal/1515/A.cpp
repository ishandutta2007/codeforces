#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 998244353;
const int N = 311;

mt19937 rnd(0);

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    int s = 0;
    int j = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];

        if(s == x)
            j = i;
    }

    cout << (s == x ? "NO" : "YES") << endl;
    if(s != x) {
        if(j != -1)
            swap(a[j], a[j + 1]);

        for(auto a1 : a)
            cout << a1 << ' ';
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}