#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int N = 30000 + 13;
const int K = 113;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int mx = 0;
    int cnt = 0;
    int sum = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        while(a[i] % 2 == 0) {
            a[i] /= 2;
            cnt++;
        }
        mx = max(mx, a[i]);
        sum += a[i];
    }

    cout << sum + mx * ((1ll << cnt) - 1) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}