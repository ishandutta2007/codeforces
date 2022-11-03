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

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> p(n, 0);
    li ans = 0;
    for(int i = 0; i < n; i++) {
//        cout << i << endl;
        vector<int> s(n, 0);
        for(int j = n - 1; j > i; j--) {
            ans += p[a[j]] * 1ll * s[a[i]];

            s[a[j]]++;
        }
        p[a[i]]++;
    }

    cout <<ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}