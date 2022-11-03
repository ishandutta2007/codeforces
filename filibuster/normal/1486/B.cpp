#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(n % 2 == 1) {
        cout << 1 << endl;
    } else {
        cout << (a[n / 2] - a[n / 2 - 1] + 1) * 1ll * (b[n / 2] - b[n / 2 - 1] + 1) << endl;
    }
}

int main() {


    int t = 1;
    cin >> t;

    while(t--)
        solve();
}