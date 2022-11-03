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

    li s = 0;
    vector<int> a(n);
    bool ans = true;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(s + a[i] < i) {
            ans = false;
        }
        s += a[i] - i;

    }

    cout << (ans ? "YES" : "NO") << endl;
}

int main() {


    int t = 1;
    cin >> t;

    while(t--)
        solve();
}