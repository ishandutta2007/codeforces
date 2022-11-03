#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

int a[N];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cout << abs(a[i]) * (i % 2 == 0 ? -1 : 1) << ' ';
    }

    cout << endl;
}

int main() {
    int t = 1;
    cin >> t;

    while(t--)
        solve();
}